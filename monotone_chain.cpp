#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define all(x) x.begin(), x.end()

vector<pii> points, hull;

int cross(pii A, pii B, pii C) {
    return (B.first - A.first)*(C.second - A.second)
        - (C.first - A.first)*(B.second - A.second);
}

void monotone_chain() {
    hull.clear();
    sort(points.begin(), points.end());
    points.erase(unique(all(points)), points.end());
    int n = points.size();

    for (int i = 0; i < n; i++) {
        while (hull.size() > 1 &&
            cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0)

            hull.pop_back();
        hull.push_back(points[i]);
    }

    auto lower_hull_length = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_hull_length &&
            cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    hull.pop_back();

    return;
}
