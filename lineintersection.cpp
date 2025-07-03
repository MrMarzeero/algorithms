//This algorithm identify line segment intersections using Vector Geometry
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

struct Point {
    int x, y;
};

int orient(Point a, Point b, Point c) {
    int cross = (b.x - a.x) * (c.y - a.y) -
        (b.y - a.y) * (c.x - a.x);

    if(cross == 0) return 0;
    return ((cross < 0) ? -1 : 1);
}

int onSeg(Point a, Point b, Point c) {
    return (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
        min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y));
}

void solve() {
    vector<Point> p(4);
    for (int i = 0; i < 4; ++i) 
        cin >> p[i].x >> p[i].y;
    int a = orient(p[0], p[1], p[2]);
    int b = orient(p[0], p[1], p[3]);
    int c = orient(p[2], p[3], p[0]);
    int d = orient(p[2], p[3], p[1]);

    int cross = true;

    if(a*b >= 0) cross = false;
    if(c*d >= 0) cross = false;

    if(a == 0 && onSeg(p[0], p[1], p[2])) cross = true;
    if(b == 0 && onSeg(p[0], p[1], p[3])) cross = true;
    if(c == 0 && onSeg(p[2], p[3], p[0])) cross = true;
    if(d == 0 && onSeg(p[2], p[3], p[1])) cross = true; 

    cout << (cross ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
