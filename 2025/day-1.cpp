#include <bits/stdc++.h>
using namespace std;


int main() {
    char dir;
    int zeroOccs = 0, currLoc = 50;

    while (cin >> dir) {
        int shift; cin >> shift;
        if (dir == 'L') shift *= -1;

        currLoc = (currLoc + shift + 100) % 100;
        if (!currLoc) zeroOccs++;
    } 

    cout << zeroOccs << endl;
    return 0;
}
