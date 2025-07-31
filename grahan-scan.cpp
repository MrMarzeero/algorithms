#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

struct Point {
	int x, y;
};

int n;
Point A;
vector<Point> points, hull;

int orientation(Point A, Point B, Point C) {
    return (B.x - A.x)*(C.y - A.y)
         - (B.y - A.y)*(C.x - A.x);
}

int cross(Point A, Point B) { return A.x*B.y - B.x*A.y; }
bool comp(Point A, Point B) {
    int cr = cross(A, B);
    if (cr != 0) 
        return cr > 0;            
    int dA = A.x*A.x + A.y*A.y;
    int dB = B.x*B.x + B.y*B.y;
    return dA < dB;
}


void graham_scan() {
	A = points[0];
	for (int i = 0; i < n; ++i) 
		if((points[i].y < A.y) || (points[i].y == A.y && points[i].x < A.x)) A = points[i];
	
	for (int i = 0; i < n; ++i) {
		points[i].x = points[i].x - A.x;
		points[i].y = points[i].y - A.y;
	}

	sort(all(points), comp);

	for (int i = 0; i < n; ++i) {
		while(hull.size() >= 2 &&
			orientation(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
				hull.pop_back();
		}	

		hull.push_back(points[i]);
	}

	for (int i = 0; i < n; ++i) {
		points[i].x += A.x;
		points[i].y += A.y;
	}
}
