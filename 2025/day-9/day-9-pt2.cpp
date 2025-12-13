#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using Point = pair<lint, lint>;
using Line = pair<Point, Point>;
using Rect = pair<Point, Point>;

/*
 * The approach utilizes Green's Theorem to
 * identify the outer border of the polygon.
 * It then tests each rectangle, verifying
 * validity if it does not intersect with
 * the outer border.
 */

bool isHorizontal(Line& line) {
    return line.first.second == line.second.second;
}


bool isClockwise(vector<Line>& lines) {
    lint total = 0;
    for (Line& line : lines) {
        auto [x1, y1] = line.first;
        auto [x2, y2] = line.second;

       total += x1 * y2 - y1 * x2;
    }
    return total > 0;
}

int main() {
    vector<Point> points;
    vector<Line> lines;

    string s;
    lint x, y;
    char trash;

    while (getline(cin, s)) {
        stringstream(s) >> x >> trash >> y;
        points.push_back({x, y});
    }
    
    Point& curr = points.back();

    for (Point& point : points) {
        lines.push_back({curr, point});
        curr = point;
    }

    bool clockwise = isClockwise(lines);

    vector<Line> borders;

    for (Line& line : lines) {
        auto [x1, y1] = line.first;
        auto [x2, y2] = line.second;
        
        bool horizontal = isHorizontal(line);
        lint shift = clockwise ? -1 : 1;
        
        if (horizontal && x2 < x1) shift *= -1;
        if (!horizontal && y1 < y2) shift *= -1;

        borders.push_back(
                horizontal ?
                Line{{min(x1, x2) + 1, y1 + shift},
                     {max(x1, x2) - 1, y2 + shift}} :
                Line{{x1 + shift, min(y1, y2) + 1},
                     {x2 + shift, max(y1, y2) - 1}}
        );
    }

    auto intersects = [](Line& line, Rect& rect) {
        auto [xmin, ymin] = rect.first;
        auto [xmax, ymax] = rect.second;

        if (isHorizontal(line)) {
            auto [x1, y] = line.first;
            lint x2 = line.second.first;

            if (x1 > x2) swap(x1, x2);

            if (y < ymin || y > ymax) return false;
            return max(x1, xmin) <= min(x2, xmax);
        }
        else {
            auto [x, y1] = line.first;
            lint y2 = line.second.second;

            if (y2 > y1) swap (y1, y2);

            if (x < xmin || x > xmax) return false;
            return max(y1, ymin) <= min(y2, ymax);
        }
    };

    lint N = points.size();
    lint best = 0;

    for (lint i = 0; i < N; i++) {
        auto [x1, y1] = points[i];

        for (lint j = i + 1; j < N; j++) {
            auto [x2, y2] = points[j];

            lint area = (abs(y2-y1)+1) * (abs(x2-x1)+1);
            if (area <= best) continue;
            
            bool valid = true;
            Rect rect = {{min(x1, x2), min(y1, y2)},
                         {max(x1, x2), max(y1, y2)}};

            for (Line& border : borders) {
                if (intersects(border, rect)) {
                    valid = false;
                    break;
                }
            }

            if (valid) best = area;
        }
    }
    
    cout << best << '\n';
    return 0;
}
