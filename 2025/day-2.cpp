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

    while (getline(ss, s, ',')) {
        stringstream temp(s);
        lint numOne, numTwo; char trash;
        temp >> numOne; temp >> trash; temp >> numTwo;

        lint numOneDigits = countDigits(numOne) + 1;
        lint curr = numOne / powers[numOneDigits >> 1];

        for (lint res = curr * powers[countDigits(curr)] + curr;
                res <= numTwo;
                curr++, res = curr * powers[countDigits(curr)] + curr) {

            if (res >= numOne) total += res;
        }
    }

    cout << total << endl;
    return 0;
}
