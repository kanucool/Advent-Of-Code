#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    string s;
    lint total = 0;

    while (cin >> s) {
        int N = s.size();
        vector<char> num;

        for (char c : s) {
            c -= '0';
            N--;

            while (!num.empty() && num.back() < c && 12 <= num.size() + N) {
                num.pop_back();
            }

            if (num.size() < 12) num.push_back(c);
        }

        lint actualNum = 0;
        for (char c : num) actualNum = actualNum * 10 + c;

        total += actualNum;
    }

    cout << total << '\n';
    return 0;
}
