//Árvore Geradora Mínima (MST)
//Otávio Pinheiro
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
struct t_aresta {
    int dis;
    int x, y;
};
 
const int maxn = 2*1e5+10;
int compo;
int parent[maxn], sz[maxn];
t_aresta aresta[maxn];
 
bool comp(t_aresta x, t_aresta y) { return x.dis < y.dis; };

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}
 
void join(int x, int y) {
    x = find(x); 
    y = find(y);
    if(x==y) return;
    compo--;
    if(sz[x] >= sz[y]) {
        sz[x] += sz[y];
        parent[y] = x;
    } else {
        sz[y] += sz[x];
        parent[x] = y;
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
 
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
 
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        aresta[i].dis = c;
        aresta[i].x = a; aresta[i].y = b;
    } 
   //Ordena pelo menor custo
  sort(aresta, aresta+m, comp);
 
    compo = n;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        //Verifica se não está no mesmo componente
        if(find(aresta[i].x) != find(aresta[i].y)) {
            join(aresta[i].x, aresta[i].y);
            ans += aresta[i].dis;
        }
    }
 
 
    if(compo != 1) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
    return 0;
}
