#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<string> grid;

    while (cin >> s) grid.push_back(move(s));
    int N = grid.size(), M = grid[0].size();

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '@') continue;

            int curr = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int x = i + dx, y = j + dy;
                    curr += x >= 0 && x < N && y >= 0
                            && y < M && grid[x][y] == '@'; 
                }
            }

            count += curr <= 4;
        }
    }

    cout << count << '\n';
    return 0;
}
