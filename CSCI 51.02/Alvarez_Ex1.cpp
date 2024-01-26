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
    return 0;
}