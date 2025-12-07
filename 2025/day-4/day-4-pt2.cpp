#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;

    Node(int x, int y) : x(x), y(y) {}
};

int main() {
    string s;
    vector<string> grid;

    while (cin >> s) grid.push_back(move(s));
    int N = grid.size(), M = grid[0].size();

    vector<vector<int>> inDegrees(N, vector<int>(M, -1));

    auto verify = [&inDegrees, &grid, N, M](int x, int y) {
        return x >= 0 && x < N && y >= 0
            && y < M && grid[x][y] == '@';
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '@') continue;

            int curr = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                        int x = i + dx, y = j + dy;

                    if (verify(x, y)) {
                        inDegrees[x][y]++;
                    }
                }
            }
        }
    }

    queue<Node> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '@' && inDegrees[i][j] < 4) {
                q.push({i,j});
            }
        }
    }

    int count = 0;

    while (!q.empty()) {
        count++;
        auto [i, j] = q.front(); q.pop();

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int x = i + dx, y = j + dy;

                if (verify(x, y)) {
                    inDegrees[x][y]--;
                    if (inDegrees[x][y] == 3) {
                        q.push({x, y});
                    }
                }
            }
        }
    }

    cout << count << '\n';
    return 0;
}
