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
int f[maxn][20], dep[maxn];
int head[maxn], to[maxn<<1], nxt[maxn<<1], w[maxn<<1], vcnt;
int id[maxn<<1];
int n;
void add(int a, int b, int c, int idd) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt; w[vcnt]=c;
    id[vcnt]=idd;
}
void dfs(int u, int dept) {
    dep[u] = dept;
    for (int i = 1; i < 20; i++) {
        if (!f[u][i-1]) break;
        else f[u][i] = f[f[u][i-1]][i-1];
    }
//    ins(ranks[u], root[u] = root[f[u][0]], 1, total);
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == f[u][0]) continue;
        f[to[i]][0] = u;
        ins(ranks[id[i]], root[to[i]]=root[u], 1, total);
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
int query3(int fa, int ss1, int ss2, int k, int l, int r) {
    if (k<=0) return 0;
    if (r<=k) return tr[ss1].sum+tr[ss2].sum-2*tr[fa].sum;
    int mid=(l+r)>>1;
    int res=0;
    res += query3(tr[fa].l, tr[ss1].l, tr[ss2].l, k, l, mid);
    if (k>mid) res+=query3(tr[fa].r, tr[ss1].r, tr[ss2].r, k, mid+1, r);
    return res;
}
#define pii pair<int, int>
int da2[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int m; scanf("%d%d", &n, &m);
    for (int i = 1, a, b, c; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c); add(a, b, c, i); add(b, a, c, i);
        da2[i]=c; da[i]=c;
    }
    sort(da2 + 1, da2 + n);
    total = unique(da2 + 1, da2 + n) - da2 - 1;
    for (int i = 1; i < n; i++) ranks[i] = lower_bound(da2 + 1, da2 + 1 + total, da[i])-da2;
    logs[0] = -1;
    for (int i = 1; i < maxn; i++) logs[i] = logs[i>>1]+1;
    dfs(1, 1);
    int a, b, k, t;
    while (m--) {
        scanf("%d%d%d", &a, &b, &k);
        t = lca(a, b);
        int rks=upper_bound(da2+1, da2+1+total, k)-da2-1;
        printf("%d\n", query3(root[t], root[a], root[b], rks, 1, total));
    }

    return 0;
}