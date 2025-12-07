#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    string s;
    vector<string> grid;

    while (getline(cin, s)) {
        grid.push_back(move(s));
    }

    int N = grid.size(), M = grid[0].size();
    vector<vector<lint>> dp(N, vector<lint>(M));

    for (int j = 0; j < M; j++) {
        if (grid[0][j] == 'S') {
            dp[0][j] = 1;
            break;
        }
    }

    lint total = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i - 1][j] != 'S') continue;

            if (grid[i][j] == '^') {

                if (j) {
                    grid[i][j - 1] = 'S';
                    dp[i][j - 1] += dp[i - 1][j];
                }
                else total += dp[i - 1][j];

                if (j < M - 1) {
                    grid[i][j + 1] = 'S';
                    dp[i][j + 1] += dp[i - 1][j];
                }
                else total += dp[i - 1][j];

            }
            else {
                grid[i][j] = 'S';
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    total = accumulate(dp[N-1].begin(), dp[N-1].end(), total);
    cout << total << '\n';
    return 0;
}
