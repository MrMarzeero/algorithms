//Extended Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

//Find ax + by = gcd(a, b) = k for given a, b
// b mod a = b - (b/a)*a
//(b mod a)x' + ay' = k <=> ... <=> a(y' - x'(b/a)) + bx' = k

//Base case: If a = 0 : The solution (x, y) = (0, 1) 
// So (x, y) = (y' - x'(b/a), x')  

int x, y;
int gcdExt(int a, int b) {
    if(a == 0) {
        x = 0; y = 1;
        return b;
    }

    int gcd = gcdExt(b % a, a);
    int lastX = x;
    x = y - x * (b / a);
    y = lastX;

    return gcd;
}
