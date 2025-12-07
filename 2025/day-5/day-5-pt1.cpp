#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct Interval {
    lint l, r;

    Interval(lint l, lint r) : l(l), r(r) {}
    auto operator<=>(const Interval&) const = default;
};

int main() {

    string s;
    vector<Interval> intervals;

    while (getline(cin, s)) {
        if (s.empty()) break;
        
        int idx = s.find("-");
        lint l = stoll(s.substr(0, idx));
        lint r = stoll(s.substr(idx + 1,
                        s.size() - idx - 1));

        intervals.push_back({l, r});
    }

    sort(intervals.begin(), intervals.end());

    vector<lint> nums;
    lint num;

    while (cin >> num) {
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int intPtr = 0, invalidCount = 0;
    int N = intervals.size();

    for (lint num : nums) {
        while (intPtr < N && intervals[intPtr].r < num) {
            intPtr++;
        }

        if (intPtr == N || intervals[intPtr].l > num) {
            invalidCount++;
        }
    }

    cout << nums.size() - invalidCount << '\n';
    return 0;
}
