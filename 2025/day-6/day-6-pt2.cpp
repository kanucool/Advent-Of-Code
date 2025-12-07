#include <bits/stdc++.h>
using namespace std;
using lint = long long;

template <typename T> requires requires(T& obj) {
    obj.begin(); obj.end(); cout << *obj.begin();
}
void printVec(vector<T>& vec, char delim = '\0') {
    for (T& row : vec) {
        for (auto& val : row) cout << val << delim;
        cout << '\n';
    }
}


int main() {
    string s;
    vector<string> lines;

    int M = 0;

    while (getline(cin, s)) {
        M = max(M, (int) s.size());
        lines.push_back(move(s));
    }

    int N = lines.size() - 1;

    vector<string> transposed(M, string(N, ' '));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            transposed[j][i] = lines[i][j] ? lines[i][j] : ' ';
        }
    }

    transposed.push_back(" ");

    vector<vector<lint>> rows;
    vector<lint> curr;

    for (string& row : transposed) {
        if (lint num; stringstream(row) >> num) {
            curr.push_back(num);
        }
        else {
            rows.push_back(move(curr));
            curr.clear();
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
