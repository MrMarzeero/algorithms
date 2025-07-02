//Fast Multiplication
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int binmul(int x, int y) {
    if(y == 0) return 0;
    int t = (2 * binmul(x, y / 2)) % mod;
    if(y % 2 == 0) return t;
    return (t + x) % mod; 
}
