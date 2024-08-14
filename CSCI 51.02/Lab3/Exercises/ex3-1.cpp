//ex3-1.cpp
#include "ex3-1.hpp"
#include <iostream>
using namespace std;

int main(void){
    Point3D point{1, 2, 3};
    cout << point.x << " " << point.y;
    cout << " " << point.z << endl;
    Point3D orig;
    cout << orig.x << " " << orig.y;
    cout << " " << orig.z << endl;

    DiffVariables vars{42, 3.14, 'A', true, "Hello", "what", {1, 2, 3, 4, 5}, {4.2, 51.1, 3.2, 5.3, 6.2}, {true, true, false, false, true}, {"hello", "hi", "world", "beautiful", "wow"}};

    cout << "----Exercises----" << endl;
    cout << "Integer: " << vars.integer << endl;
    cout << "Floating Point: " << vars.floatingPoint << endl;
    cout << "Character: " << vars.character << endl;
    cout << "Boolean: " << boolalpha << vars.boolean << endl;
    cout << "String: " << boolalpha << vars.str << endl;
    cout << "Character Array: " << boolalpha << vars.charArray << endl;
    cout << "Integer Array: " << boolalpha << vars.intArray << endl;
    cout << "Floating Point Array: " << boolalpha << vars.floatArray << endl;
    cout << "Boolean Array: " << boolalpha << vars.boolArray << endl;
    cout << "String Array: " << boolalpha << vars.strArray << endl;

    cout << "---Proper Printing of Arrays---" << endl;
    cout << "Character Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << vars.charArray[i] << " ";
    }
    cout << endl;
    cout << "Integer Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << vars.intArray[i] << " ";
    }
    cout << endl;
    cout << "Floating Point Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << vars.floatArray[i] << " ";
    }
    cout << endl;
    cout << "Boolean Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << vars.boolArray[i] << " ";
    }
    cout << endl;
    cout << "String Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << vars.strArray[i] << " ";
    }
    cout << endl << endl;

    DiffVariables original;
    cout << "----Newly Initiated Struct----" << endl;
    cout << "Integer: " << original.integer << endl;
    cout << "Floating Point: " << original.floatingPoint << endl;
    cout << "Character: " << original.character << endl;
    cout << "Boolean: " << boolalpha << original.boolean << endl;
    cout << "String: " << boolalpha << original.str << endl;
    cout << "Character Array: " << boolalpha << original.charArray << endl;
    cout << "Integer Array: " << boolalpha << original.intArray << endl;
    cout << "Floating Point Array: " << boolalpha << original.floatArray << endl;
    cout << "Boolean Array: " << boolalpha << original.boolArray << endl;
    cout << "String Array: " << boolalpha << original.strArray << endl;

    cout << "---Proper Printing of Arrays---" << endl;
    cout << "Character Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << original.charArray[i] << " ";
    }
    cout << endl;
    cout << "Integer Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << original.intArray[i] << " ";
    }
    cout << endl;
    cout << "Floating Point Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << original.floatArray[i] << " ";
    }
    cout << endl;
    cout << "Boolean Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << original.boolArray[i] << " ";
    }
    cout << endl;
    cout << "String Array: " ;
    for (int i = 0; i < 5; i++) {
        cout << original.strArray[i] << " ";
    }
    cout << endl;

    return 0;
}