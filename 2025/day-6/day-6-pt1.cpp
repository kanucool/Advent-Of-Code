#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    string s;
    vector<string> lines;

    while (getline(cin, s)) {
        lines.push_back(move(s));
    }

    int N = lines.size() - 1;
    vector<vector<lint>> rows;

    for (int i = 0; i < N; i++) {
        stringstream ss(lines[i]);

        for (lint num, ptr = 0; ss >> num; ptr++) {
            if (ptr == rows.size()) {
                rows.push_back(vector<lint>());
            }

            rows[ptr].push_back(num);
        }
    }

    lint total = 0;
    int ptr = 0;

    stringstream ss(lines[N]);

    for (char op; ss >> op;) {
        total += accumulate(rows[ptr].begin(), rows[ptr].end(),
                    (lint) (op == '*' ? 1 : 0), [op](auto a, auto b) {
                        return op == '*' ? a * b : a + b;
                    });
        ptr++;
    }

    cout << total << '\n';
    return 0;
}
