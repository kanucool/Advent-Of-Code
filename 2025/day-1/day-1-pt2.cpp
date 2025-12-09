#include <bits/stdc++.h>
using namespace std;


int main() {
    char dir;
    int zeroOccs = 0, currLoc = 50;

    while (cin >> dir) {
        int shift; cin >> shift;
        if (dir == 'L') shift *= -1;
        
        zeroOccs += (abs(shift) +
                    (shift < 0 && currLoc ? 100 - currLoc : currLoc))
                    / 100;
        currLoc = (((currLoc + shift) % 100) + 100) % 100;
    } 

    cout << zeroOccs << endl;
    return 0;
}
