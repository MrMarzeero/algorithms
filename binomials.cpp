#include <bits/stdc++.h>
using namespace std;

#define int long long

//This solves the problem in O(n log n) when k is prime (using Fermat Little Theorem)
//Alternatively, you can build Pascal's Triangle for O(n²) time regardless of k

const int maxn = 1e6 + 10;
int m;
int fact[maxn];

int binpow(int x, int y) {
    if(y == 0) return 1;
    int t = binpow(x, y / 2);
    t = (t * t) % m;
    if(y % 2 == 0) return t;
    return (t * x) % m;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k >> m;
    if(k > n) {
        cout << "0\n";
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % m;
    int res = (((fact[n]*binpow(fact[k], m - 2)) % m) * binpow(fact[n - k], m - 2)) % m;
    cout << res << '\n';
    return 0;
}
