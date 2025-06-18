// Binary Indexed Tree (BIT)
// Otávio Pinheiro
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e5 + 10;

int n; 
int bit[maxn];

//Atualizar posições na BIT
void upd(int x, int u) {
    while(x <= n) {
        bit[x] += u;
        x+=x&-x;
    }
}
 
//Retorna a[1]+...+a[x]
int query(int x) {
    int s = 0;
    while(x > 0) {
        s+=bit[x];
        x-=x&-x;
    }
    return s;
}
