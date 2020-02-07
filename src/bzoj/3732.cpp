#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e4;
int f[maxn][20], g[maxn][20];
int dep[maxn];
int fa[maxn];
int n, m, k;
struct node2 {
    int v, w, nxt;
}v[maxn << 1];
int head[maxn], cnt = 1;
void add(int a, int b, int c) {
    v[cnt] = (node2) {b, c, head[a]}; head[a] = cnt++;
}
struct node {
    int u, v, w;
    bool operator < (const node& tmp) const {
        return w > tmp.w;
    }
};
void init() {
    for (int i = 0; i < maxn; i++) fa[i] = i;
}
int fin(int a) {
    if (fa[a] != a) return fa[a] = fin(fa[a]);
    return a;
}
void dfs(int u, int dept, int fa) {
    for (int i = head[u]; i; i = v[i].nxt) {
        int to = v[i].v;
        if (to == fa) continue;
        dep[to] = dep[u] + 1;
        f[to][0] = u, g[to][0] = v[i].w;
        dfs(to, dept+1, u);
    }
}
void deal() {
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
            g[j][i] = max(g[j][i-1], g[f[j][i-1]][i-1]);
        }
    }
}
int lca(int a, int b) {
    int ans = 0;
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (dep[f[a][i]] >= dep[b]) ans = max(ans, g[a][i]), a = f[a][i];
    }
    if (a == b) return ans;
    for (int i = 19; i >= 0; i--) {
        if (f[a][i] != f[b][i]) {
            ans = max(ans, max(g[a][i], g[b][i]));
            a = f[a][i], b = f[b][i];
        }
    }
    ans = max(ans, max(g[a][0], g[b][0]));
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    priority_queue<node> q;
    init();
    scanf("%d%d%d", &n, &m, &k);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        q.push((node) {a, b, c});
    }
    node tmp;
    while (!q.empty()) {
        tmp = q.top(); q.pop();
        a = fin(tmp.u), b = fin(tmp.v);
        if (a == b) continue;
        fa[a] = b;
        add(tmp.u, tmp.v, tmp.w);
        add(tmp.v, tmp.u, tmp.w);
    }
    dfs(1, 0, -1);
    deal();
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}