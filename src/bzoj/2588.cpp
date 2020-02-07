#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5 + 100;
int da[maxn], ranks[maxn];
struct node {
    int l, r, sum;
} tr[maxn*20];
int root[maxn];
int Tcnt, total;
void ins(int num, int& x, int l, int r) {
    tr[++Tcnt] = tr[x]; x = Tcnt; tr[x].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (num <= mid) ins(num, tr[x].l, l, mid);
    else ins(num, tr[x].r, mid+1, r);
}
int query(int ss, int bs, int k, int l, int r) {
    if (l == r) return l;
    int d = tr[tr[bs].l].sum - tr[tr[ss].l].sum;
    int mid = (l + r) >> 1;
    if (k <= d) return query(tr[ss].l, tr[bs].l, k, l, mid);
    else return query(tr[ss].r, tr[bs].r, k - d, mid+1, r);
}
int f[maxn][20], dep[maxn];
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
int n;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
void dfs(int u, int dept) {
    dep[u] = dept;
    for (int i = 1; i < 20; i++) {
        if (!f[u][i-1]) break;
        else f[u][i] = f[f[u][i-1]][i-1];
    }
    ins(ranks[u], root[u] = root[f[u][0]], 1, total);
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == f[u][0]) continue;
        f[to[i]][0] = u; 
        dfs(to[i], dept+1);
    }
}
int logs[maxn];
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 0, d = dep[a] - dep[b]; d; d>>=1, i++) {
        if (d&1) a = f[a][i];
    }
    if (a == b) return a;
    for (int i = logs[n]; i >= 0; i--) {
        if (f[a][i] != f[b][i]) a = f[a][i], b = f[b][i];
    }
    return f[a][0];
}
int query2(int ss1, int ss2, int bs1, int bs2, int k, int l, int r) {
    if (l == r) return l; int mid = (l + r) >> 1;
    int d = tr[tr[bs1].l].sum + tr[tr[bs2].l].sum - tr[tr[ss1].l].sum - tr[tr[ss2].l].sum;
    if (k <= d) return query2(tr[ss1].l, tr[ss2].l, tr[bs1].l, tr[bs2].l, k, l, mid);
    else return query2(tr[ss1].r, tr[ss2].r, tr[bs1].r, tr[bs2].r, k - d, mid + 1, r);
}
#define pii pair<int, int>
int da2[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int m; scanf("%d%d", &n, &m);
    for (int i = 1, tmp; i <= n; i++) {
        scanf("%d", &tmp); 
        da[i] = tmp; da2[i] =  tmp;
    } 
    sort(da2 + 1, da2 + 1 + n);
    logs[0] = -1;
    for (int i = 1; i < maxn; i++) logs[i] = logs[i>>1]+1;
    total = unique(da2 + 1, da2 + 1 + n) - da2 - 1;
    for (int i = 1; i <= n; i++) ranks[i] = lower_bound(da2 + 1, da2 + 1 + total, da[i]) - da2;
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b); add(a, b); add(b, a);
    }
    dfs(1, 1);
    int ans = 0, a, b, k, t;
    while (m--) {
        scanf("%d%d%d", &a, &b, &k);
        a ^= ans; t = lca(a, b);
        printf("%d", ans = da2[query2(root[t], root[f[t][0]], root[a], root[b], k, 1, total)]);
        if (m) printf("\n");
    }
    
    return 0;
}