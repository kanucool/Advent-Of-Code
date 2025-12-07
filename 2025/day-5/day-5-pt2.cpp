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
    intervals.push_back({LLONG_MAX, LLONG_MAX});

    lint currStart = 1, currEnd = 0, total = 0;

    for (auto [start, end]: intervals) {
        if (start <= currEnd) {
            currEnd = max(end, currEnd);
        }
        else {
            total += currEnd - currStart + 1;
            currStart = start;
            currEnd = end;
        }
    }


    cout << total << '\n';
    return 0;
}
