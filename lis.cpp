#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e12;

int32_t main() {
    //Algoritimo Longest Increasing Subsequence
    //DP O(n²)/O(nlogn) approach
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    vector<int> dp(n+1);
    dp[0] = -inf;
    for (int i = 1; i <= n; ++i)
        dp[i] = inf;

    //O(n²) approach
    // for (int i = 1; i <= n; ++i) {
        // for (int j = 1; j <= n; ++j) { 
            // if(dp[j-1] < a[i]) dp[j] = min(dp[j], a[i]);
        // } 
    // }


    //O(nlogn) approach
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[p] = a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        if(dp[i] != inf) ans = i;
    cout << ans << '\n';
    return 0;
}
