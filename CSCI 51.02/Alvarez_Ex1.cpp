#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "### Exercise 1.1 ###" << endl;
    for(int i = 0; i < argc; i++) {
        cout << "arg" << i << ":" << argv[i];
        cout << endl;
    }

    cout << endl << "### Exercise 1.2 ###" << endl;

    for(int i = 0; i < argc; i++) {
        cout << "arg" << i << ":";
        for(int j = strlen(argv[i]); j >= 0; j--) {
            cout << argv[i][j];
        } 
        cout << endl;
    }

    cout << endl << "### Exercise 1.3 ###" << endl;
    for(int i = 0; i < argc; i++) {
        printf("%c\n", argv[i][0]); //Prints the first Character of the String
        printf("%s\n", argv[i]+1); //Shifts the start of the string 1 character to the left
    }
    return 0;
}