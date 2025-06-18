#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e5 + 10;

int a[maxn];

struct SegTree {
    int tree[4*maxn], lz[4*maxn];
    void unlazy(int node, int tl, int tr) {
        tree[node] += (tr-tl+1)*lz[node];
        if(tl != tr) {
            lz[2*node] += lz[node];
            lz[2*node + 1] += lz[node];
        }
        lz[node] = 0;
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l+r) / 2;
        build(2*node, l, mid);
        build(2*node + 1, mid + 1, r);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }

    void update(int node, int l, int r, int tl, int tr, int val) {
        unlazy(node, tl, tr);
        if(tl > r || tr < l) return;
        if(tl >= l && tr <= r) {
            lz[node] += val;
            unlazy(node, tl, tr);
            return;
        }

        int mid = (tl + tr) / 2;
        update(2*node, l, r, tl, mid, val);
        update(2*node + 1, l, r, mid+1, tr, val);
        tree[node] = tree[2*node] + tree[2*node + 1]; 
    }

    int query(int node, int tl, int tr, int x) {
        unlazy(node, tl, tr);
        if(tl == tr) return tree[node];            

        int mid = (tl + tr) / 2;
        if(x <= mid) return query(2*node, tl, mid, x);
        return query(2*node + 1, mid + 1, tr, x);
    }

} seg;
