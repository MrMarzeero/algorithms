//Modular Inverse (m prime)
#include <bits/stdc++.h>
using namespace std;

#define int long long

int m;

int binpow(int x, int y) {
    if(y == 0) return 1;
    int t = binpow(x, y / 2);
    t = (t * t) % m;
    if(y % 2 == 0) return t % m;
    return (t * x) % m;
}

int32_t main() {
    int a; cin >> a >> m;
    if(a % m == 0) {
        cout << "inexistent\n";
        return 0;
    }
    cout << binpow(a, m - 2) << '\n';
}
