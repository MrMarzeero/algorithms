//Fast Exponentiantion
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int binpow(int x, int y) {
    if(y == 0) return 1;
    int t = binpow(x, y / 2);
    t = (t * t) % mod;
    if(y % 2 == 0) return t;
    return (t * x) % mod;
}
