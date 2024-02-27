#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    // Normal Input of Name
    string name;
    cout << "1. ";
    cin >> name;

    // Normal Output of Name
    cout << "2. " << name << endl;

    // First Character + Letters Replaced with #
    char* name_chr = &name[0]; 
    cout << "3. " << name_chr[0];
    for(int i = 0; i < name.length()-1; i++) {
        cout << "#";
    }
    cout << endl;

    //Shift Characters 1 to the Right
    cout << "4. "; 
    while (*name_chr != 0) {
        if (isupper(*name_chr)) {
            cout << char((int(*name_chr) - 64) % 26 + 65); // Shift Uppercase Letters to the Right
        } else if (islower(*name_chr)) {
            cout << char((int(*name_chr) - 96) % 26 + 97); // Shift Lowercase Letters to the Right
        } else {
            cout << *name_chr;
        }
        name_chr++;
    }
}