#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint total = 0;

    string blocks; cin >> blocks;
    stringstream ss(blocks);

    string s;

    auto countDigits = [](lint a) {
        lint numDigits = 0;
        while (a) {
            numDigits++;
            a /= 10;
        }
        return numDigits;
    };

    vector<lint> powers = {1};
    for (lint i = 1; i <= 17; i++) {
        powers.push_back(powers.back() * 10);
    }

    set<lint> seen;

    while (getline(ss, s, ',')) {
        stringstream temp(s);
        lint numOne, numTwo; char trash;
        temp >> numOne; temp >> trash; temp >> numTwo;

        lint curr = 1;

        for (   lint currDigits = countDigits(curr),
                res = curr * powers[currDigits] + curr;
                res <= numTwo;
                currDigits = countDigits(++curr),
                res = curr * powers[currDigits] + curr) {
            
            while (res <= numTwo) {
                if (res >= numOne && seen.find(res) == seen.end()) {
                    seen.insert(res);
                    total += res;
                }
                res = res * powers[currDigits] + curr;
            }
        }
    }

    cout << total << endl;
    return 0;
}
