//Line Sweep 
//# points contained in a rectangle
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

struct Event {
    int yL, yR;
    int x, type;
    Event(int x, int yL, int yR, int type):
        x(x), yL(yL), yR(yR), type(type) {}

    bool operator<(Event a) {
        if(x != a.x)
            return x < a.x;
        return type < a.type;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<Event> sweep;
    for (int i = 0; i < n; ++i) {
        int xL, yL, xR, yR;
        cin >> xL >> yL >> xR >> yR;
        sweep.push_back(Event(xL, yL, yR, 0));
        sweep.push_back(Event(xR, yL, yR, 2));
    }

    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        sweep.push_back(Event(x, y, y, 1));
    }

    sort(sweep.begin(), sweep.end());

    int res = 0;
    set<pii> intervals;
    for (int i = 0; i < (int)sweep.size(); ++i) {
        int type = sweep[i].type;
        int l = sweep[i].yL, r = sweep[i].yR;
        if(type == 0) intervals.insert({l, r});
        else if(type == 1) {
            auto it = intervals.upper_bound({l + 1, 0});
            if(it != intervals.begin()) {
                it--;
                if((*it).first <= l && l <= (*it).second)
                    res++;
            }
        } else intervals.erase({l, r}); 
    }
    cout << res << '\n';
    return 0;
}
