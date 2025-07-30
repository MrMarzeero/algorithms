#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

vector<pii> S;

double dist(pii A, pii B) {
    int xDif = abs(A.first - B.first);
    int yDif = abs(A.second - B.second);

    double res = sqrt(xDif*xDif + yDif*yDif);
    return res;
}


double closest_pair_dist() {
    sort(S.begin(), S.end());

    double ans = dist(S[0], S[1]); 
    int p = 0;

    set<pii> activatedPoints;
    for (int i = 0; i < (int)S.size(); ++i) {
        while(double(S[i].first - S[p].first) > ans) {
            activatedPoints.erase({S[p].second, p});
            p++;
        }    

        auto it = activatedPoints.lower_bound({(int)(S[i].second - floor(ans)), 0});
        while(it != activatedPoints.end() && it->first <= S[i].second + floor(ans)) {
            ans = min(ans, dist(S[it->second], S[i]));
            it++;
        }

        activatedPoints.insert({S[i].second, i});
    } 

    return ans;
}
