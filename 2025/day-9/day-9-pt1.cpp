#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    string s;
    char trash;
    vector<pair<lint, lint>> points;

    while (getline(cin, s)) {
        lint x, y;
        stringstream(s) >> x >> trash >> y;
        points.push_back({x, y});
    }

    auto area = [](auto& a, auto &b) {
        return (abs(a.first-b.first)+1) *
               ((abs(a.second-b.second)+1));
    };

    lint N = points.size(), res = 0;
    
    for (lint i = 0; i < N; i++) {
        for (lint j = i + 1; j < N; j++) {
            res = max(res, area(points[i], points[j]));
        }
    }

    cout << res << '\n';
    return 0;
}
