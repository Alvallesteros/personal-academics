/* Alvarez, Angelo Joaquin
Espera, Julia Anishka
Panghulan, Ysabella
CSCI 50.02 Section C
Lab 4 Intro to Assembly I : GAS & AT&T Syntax
March 4, 2024
*/

#include <iostream>
using namespace std;

int dummy(int x, int y) {
    int result = 0;
    bool signX = (x < 0) ? true : false;
    bool signY = (y < 0) ? true : false;

    x = abs(x);
    y = abs(y);

    while (y != 0) {
        if (y & 1) {
            result += x;
        }
        x <<= 1;
        y >>= 1;
    }

    if  ((signX || signY) && (signX != signY)) {
        return -result;
    }

    return result;
}

int main() {
    cout << "multiply by 19: " << dummy(2, 19) << endl;
    cout << "multiply by 45: " << dummy(2, 45) << endl;
    cout << "multiply by -2: " << dummy(2, -2) << endl;
    cout << "multiply by 0: " << dummy(2, 0) << endl;
    cout << "when x is negative: " << dummy(-2, 6) << endl;
    cout << "when y is negative: " << dummy(2, -6) << endl;
    cout << "when x and y are negative: " << dummy(-2, -6) << endl;
    
    return 0;
}