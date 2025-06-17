#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e5 + 10;

int a[maxn];

struct SegTree {
    int tree[4*maxn];
    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l+r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    void update(int node, int l, int r, int pos, int val) {
        if(l == r) {
            tree[node] += val;
            return;
        }

        int mid = (l + r)/2;
        if(pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node + 1, mid+1, r, pos, val); 
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    int query(int node, int l, int r, int tl, int tr) {
        if(tl >= l && tr <= r) return tree[node];
        if(tl > r || tr < l) return 0;

        int mid = (tl + tr) / 2;
        return query(2*node, l, r, tl, mid) + query(2*node + 1, l, r, mid + 1, tr);
    }
} seg;
