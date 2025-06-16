//Dynamic Programming - Longest Common Subsequence O(n²)
//Otávio Pinheiro
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 1e3 + 10;
int dp[maxn][maxn];

int32_t main() {
    string a, b; cin >> a >> b;
    int n = (int)a.size();
    int m = (int)b.size();
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}
