#include <bits/stdc++.h>
using namespace std;

#define int long long

struct point {
    int x, y;
    int half() {
        return (y < 0 || y == 0 && x < 0);
    }
};

vector<point> points;

int cross(point A, point B) { return A.x*B.y - A.y*B.x; }

bool comp(point A, point B) {
    if(A.half() != B.half()) 
        return A.half()<B.half();

    if(cross(A, B) != 0) 
        return cross(A,B)>0;
    int dA = A.x*A.x + A.y*A.y;
    int dB = B.x*B.x + B.y*B.y;
    return dA<dB;
}
