#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int agentNum;
    cin >> agentNum;
    for (int i = 1; i <= agentNum; i++) {
        int j, k;
        cin >> j >> k;
        string s;
        getline(cin, s);
        printf("Agent: %d is at (%d, %d)\n", i, j, k);
        cout << "Say: " << s << endl;
    }
}