//Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

//mdc(a, b) = mdc(b, a mod b)
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}
