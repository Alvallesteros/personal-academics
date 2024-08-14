#!/usr/bin/env python3

__doc__ = '''
This is a pure Python implementation of the SHA-1 hash function.
Most of the code here is yoinked from another Python SHA-1 implementation
found here: https://github.com/ajalt/python-sha1/blob/master/sha1.py.

The `SHA1` class tries to mimic the `hashlib` API as closely as possible.
As such, the following methods are provided:

  * `update(arg)`: Update the SHA1 object with the string `arg`. Repeated calls
                   are equivalent to a single call with the concatenation of
                   all the arguments.

  * `digest()`:    Return the digest of the strings passed to the `update`
                   method so far, as a bytestring.

  * `hexdigest()`: Like `digest` except the digest is returned as a hex string.


Important note: all constants used by SHA-1 are expressed in big-endian
(i.e., the least-significant byte appears first).
'''

from binascii import unhexlify
from io import BytesIO
import struct

def _lrot(n, b):
    '''
    Left rotate a 32-bit integer `n` by `b` bits.
    '''
    return ((n << b) | (n >> (32-b))) & 0xffffffff

def _sha1_compress(chunk, h0, h1, h2, h3, h4):
    '''
    SHA-1 compression function. Process a chunk of data and return
    the new digest variables.
    '''
    assert len(chunk) == 64, 'Chunk must be 64 bytes long'

    w = [0] * 80

    # Break chunk into sixteen 4-byte big-endian words `w[i]`
    for i in range(16):
        w[i] = struct.unpack(b'>I', chunk[i*4: i*4 + 4])[0]

    # Extend the sixteen 4-byte words into eighty 4-byte words
    for i in range(16, 80):
        w[i] = _lrot(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1)

    # Initialize digest values for this chunk
    a, b, c, d, e = h0, h1, h2, h3, h4

    # Remark: Ideally, this should be implemented without if
    # statements (a.k.a. "branchless"), but this is fine for
    # our purposes.
    for i in range(80):
        if 0 <= i <= 19:
            f = d ^ (b & (c ^ d))
            k = 0x5a827999
        elif 20 <= i <= 39:
            f = b ^ c ^ d
            k = 0x6ed9eba1
        elif 40 <= i <= 59:
            f = (b & c) | (b & d) | (c & d)
            k = 0x8f1bbcdc
        elif 60 <= i <= 79:
            f = b ^ c ^ d
            k = 0xca62c1d6

        temp = (_lrot(a, 5) + f + e + k + w[i]) & 0xffffffff
        a, b, c, d, e = temp, a, _lrot(b, 30), c, d

    # Add this chunk's hash to result so far
    h0 = (h0 + a) & 0xffffffff
    h1 = (h1 + b) & 0xffffffff
    h2 = (h2 + c) & 0xffffffff
    h3 = (h3 + d) & 0xffffffff
    h4 = (h4 + e) & 0xffffffff

    return h0, h1, h2, h3, h4

def padding(message_bits):
    '''
    Generates the padding that should be appended to the end of a message
    of the given size (in bits) to reach a multiple of the block size.
    '''
    message_bytes = message_bits >> 3
    # Start with the bit `1`
    pad = b'\x80'

    # Append 0 <= k < 512 bits `0`, so that the resulting message
    # length (in bytes) is congruent to 56 mod 64 (i.e. k % 64 == 56)
    pad += b'\x00' * ((56 - (message_bytes + 1) % 64) % 64)

    # Append length of message (before pre-processing), in bits, as a
    # 64-bit big-endian integer.
    pad += struct.pack(b'>Q', message_bits)

    return pad


class SHA1:
    # digest size in bytes
    digest_size = 20
    # block size in bytes
    block_size = 64

    def __init__(self, state=None, length=0):
        '''
        Return a new SHA1 hash object, optionally initialized to a given
        internal state and length of message (in bytes) processed so far.
        '''
        if state is None:
            # Initial digest variables with magic 32-bit constants as
            # defined in the NIST standard (FIPS 180-4)
            #
            # Fun fact: These magic constants are just
            #   01234567 89abcdef fedcba98 76543210 f0e1d2c3
            # expressed as big-endian!
            # We call these as "nothing-up-my-sleeve" numbers.
            self._h = (
                0x67452301,
                0xefcdab89,
                0x98badcfe,
                0x10325476,
                0xc3d2e1f0,
            )
        else:
            # Derive values of digest variables from `state`, which is
            # given as a bytes object.
            try:
                unhexed = unhexlify(state)
                self._h = tuple(struct.unpack(b'>5I', unhexed[:self.digest_size]))
            except:
                raise Exception('Parameter `state` must be hexlified first')

        # Bytes object with 0 <= len < 64 used to store the end of
        # the message if the message length is not divisible by 64
        self._unprocessed = b''
        # Length in bytes of all data that has been processed so far
        self._message_byte_length = length

    def update(self, arg):
        '''
        Update the current digest.

        This may be called repeatedly, even after calling `digest` or
        `hexdigest`.

        Arguments:
            `arg`: bytes or bytearray object to read from.
        '''
        if isinstance(arg, (bytes, bytearray)):
            arg = BytesIO(arg)

        # Try to build a chunk out of the unprocessed data, if any
        chunk = self._unprocessed + arg.read(64 - len(self._unprocessed))

        # Read the rest of the data, 64 bytes at a time
        while len(chunk) == 64:
            self._h = _sha1_compress(chunk, *self._h)
            self._message_byte_length += 64
            chunk = arg.read(64)

        self._unprocessed = chunk
        return self

    def digest(self):
        '''
        Produce the final hash value (big-endian) as a bytes object.
        '''
        return b''.join(struct.pack(b'>I', h) for h in self._produce_digest())

    def hexdigest(self):
        '''
        Produce the final hash value (big-endian) as a hex string.
        '''
        return '{:08x}{:08x}{:08x}{:08x}{:08x}'.format(*self._produce_digest())

    def _produce_digest(self):
        '''
        (Internal function.) Return finalized digest variables for the
        data processed so far.
        '''
        # Pre-processing
        message = self._unprocessed
        message_byte_length = self._message_byte_length + len(message)

        # Apply message padding
        message += padding(message_byte_length * 8)

        # Process the final chunk. At this point, the length of the message
        # is either 64 or 128 bytes.
        h = _sha1_compress(message[:64], *self._h)
        if len(message) == 64:
            return h
        return _sha1_compress(message[:64], *h)

if __name__ == '__main__':
    from hashlib import sha1 as sha1_reference

    test_str = b'hello world this is my own SHA-1 pog'
    sha1 = SHA1()
    sha1.update(test_str)
    print(f'my SHA-1 hash: {sha1.hexdigest()}')

    # compare with a real implementation
    print(f'actual SHA-1 hash: {sha1_reference(test_str).hexdigest()}')
