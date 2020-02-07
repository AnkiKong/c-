#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e5;
const int maxm=6e5;
int n, sz;
int head[maxm], to[maxm<<1], nxt[maxm<<1], vcnt;
int LOG[maxm];
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
int now[maxm];

int dep[maxm], f[maxm][20];
void dfs(int u, int fa) {
    f[u][0] = fa; dep[u] = dep[fa] + 1;
    for (int i = 1; i < 20; i++) {
        if (f[u][i-1]) f[u][i] = f[f[u][i-1]][i-1];
        else break;
    }
    for (int i = head[u], t; i; i = nxt[i]) {
        t = to[i]; if (t == fa) continue;
        dfs(t, u);
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 0, d = dep[a] - dep[b]; d; d>>=1, i++) {
        if (d & 1) a = f[a][i];
    }
    if (a == b) return a;
    for (int i = LOG[sz]; ~i; i--) {
        if (f[a][i] != f[b][i]) a = f[a][i], b = f[b][i];
    }
    return f[a][0];
}
ll w[maxm];
struct node {
    int id, lcas, a, b;
}react[maxm];
bool cmp(node a, node b) {
    if (dep[a.lcas] != dep[b.lcas]) return dep[a.lcas] > dep[b.lcas];
    return a.id < b.id;
}
// bool cmp2(int a, int b) {
//     return a > b;
// }
bool haFa[maxm];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int m, k; scanf("%d%d%d", &n, &m, &k);
    // int tst[] = {1, 2, 3, 4};
    // sort(tst, tst + 3, cmp2);
    // printf("%d\n", tst[0]);
    LOG[0] = -1;
    for (int i = 1; i < maxm; i++) LOG[i] = LOG[i>>1]+1;
    for (int i = 0; i <= n; i++) now[i] = i;
    sz = n;
    for (int i = 1; i <= n; i++) scanf(lld, w + i);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        haFa[now[a]] = haFa[now[b]] = 1;
        ++sz; add(sz, now[a]), add(sz, now[b]); now[b] = sz;
    }
    for (int i = 1; i <= sz; i++) 
        if (!haFa[i]) 
            dfs(i, 0);
    for (int i = 0, a, b; i < k; i++) {
        scanf("%d%d", &a, &b);
        react[i] = (node) {i, lca(a, b), a, b};
    }
    sort(react, react+k, cmp);
    ll ans = 0;
    for (int i = 0, de; i < k; i++) {
        if (react[i].lcas == 0) continue;
        de = min(w[react[i].a], w[react[i].b]);
        w[react[i].a] -= de, w[react[i].b] -= de;
        ans += 1LL*de * 2;
    }
    printf(lld, ans);
    return 0;
}