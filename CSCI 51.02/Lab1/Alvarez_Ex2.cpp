#include <iostream>
using namespace std;

int main(void) {

    //Examples
    int i;
    int *p;
    p = &i;
    i = 32;

    cout << "int i: " << i << endl;
    cout << "pointer p: " << p << endl;
    cout << "address of i: " << &i << endl;
    cout << "dereference of p: " << *p << endl;
    
    //Some Practices
    //Operations with the Address
    cout << "Adding with pointer: " << p + 4 << endl;
    cout << "Dereferencing operations: " << *(p + 4) << endl;
    cout << "Dereferencing with address: " << *(&i + 4) << endl;

    //Using Characters
    char a;
    char* q;
    q = &a;
    a = 'c';
    cout << "char a: " << a << endl;
    cout << "pointer q: " << q << endl;
    cout << "address of a: " << &a << endl;
    cout << "dereference of q: " << *q << endl;

    //Operations with Characters?
    cout << "Adding with chracter pointer: " << q + 4 << endl;
    cout << "Dereferencing operations with character pointer: " << *(q + 4) << endl;
    cout << "Dereferencing with address of character: " << *(&a + 4) << endl;
    cout << "Adding with character: " << (a + 4) << endl;

    //Using Strings
    char b[] = "Hallo";
    char *str_ptr = b;

    cout << "string b: " << b << endl;
    cout << "pointer str_ptr: " << str_ptr << endl;
    cout << "address of b: " << &b << endl;
    printf("dereference of str_ptr: %s\n", str_ptr);

    //Operations with String
    cout << "Adding with string pointer: " << str_ptr + 4 << endl;
    cout << "Dereferencing operations with string pointer: " << *(str_ptr + 4) << endl;
    cout << "Dereferencing with address of string: " << *(&b + 4) << endl;
    cout << "Adding with string: " << (b + 4) << endl;
}