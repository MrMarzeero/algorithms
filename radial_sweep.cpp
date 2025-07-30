#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

vector<pii> points;

int cross(pii A, pii B) {return A.first*B.second - B.first*A.second;}
int calc(pii A) {return A.first*A.first+A.second*A.second; }

bool regionValue(pii A) {
    if(A.second > 0 || (A.second == 0 && A.first > 0)) 
        return 0;
    return 1;
}

bool comp(pii A, pii B) {
    if(regionValue(A) != regionValue(B))
        return regionValue(A)<regionValue(B);
    if(cross(A, B) != 0)
        return (cross(A,B)>0);
    return calc(A)<calc(B);
}
