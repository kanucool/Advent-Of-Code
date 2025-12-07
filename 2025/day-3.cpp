#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int total = 0;

    while (cin >> s) {
        char prevBestDigit = 0;
        char bestCurr = 0;

        for (char c : s) {
            bestCurr = max(bestCurr, (char) (prevBestDigit * 10 + c - '0'));
            prevBestDigit = max(prevBestDigit, (char) (c - '0'));
        }

        total += bestCurr;
    }

    cout << total << '\n';
    return 0;
}
