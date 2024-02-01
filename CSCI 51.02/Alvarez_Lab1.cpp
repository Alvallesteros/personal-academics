#include <iostream>
#include <string>
using namespace std;

string smallAlpha = "abcdefghijklmnopqrstuvwxyz";
string bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int shiftLetter(char* letterLoc);

int main(void) {
    string name;
    cout << "What's your name?: ";
    cin >> name; 

    // print name
    cout << "1. " << name << endl;

    // print name with only first letter and #####
    cout << "2. " << name[0];
    for(int n = 1; n < name.length(); n++)
    {
        cout << "#";
    }
    cout << endl;

    // shift letters
    cout << "3. ";
    for( int i =  0; i < name.length(); i++  ) // for strings
    {    
        shiftLetter(&name[i]);
    }
    cout << name << endl;
    return 0;
}

int shiftLetter(char* letterLoc)
{
    string* alphaUsed;
    
    // assign which string alphabet will be referenced
    if (smallAlpha.find(*letterLoc) != string::npos) // small
    {
        alphaUsed = &smallAlpha;
    }
    else if (bigAlpha.find(*letterLoc) != string::npos) // capital
    {
        alphaUsed = &bigAlpha;
    }
    else // found in neither
    {
        return 1;
    }

    int pos = alphaUsed->find(*letterLoc); // 
    int newPos = (pos + 1) % 26; // mod for Zz cases
    
    *letterLoc = alphaUsed->at(newPos);
    return 0;
}