#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    vector<string> grid;

    while (getline(cin, s)) {
        grid.push_back(move(s));
    }

    int N = grid.size(), M = grid[0].size();
    int splits = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i - 1][j] != 'S') continue;

            if (grid[i][j] == '^') {
                splits++;

                if (j) grid[i][j - 1] = 'S';
                if (j < M - 1) {
                    grid[i][j + 1] = 'S';
                }
            }
            else {
                grid[i][j] = 'S';
            }
        }
    }

    cout << splits << '\n';
    return 0;
}
