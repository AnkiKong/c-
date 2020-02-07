#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e5+100;
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;    
}

int son[maxn], sz[maxn], dep[maxn], fa[maxn];
int sum[maxn], id[maxn], top[maxn], idd;
void dfs1(int u, int f) {
    fa[u] = f; sz[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == f) continue;
        dep[to[i]] = dep[u] + 1; dfs1(to[i], u);
        sz[u] += sz[to[i]];
        if (sz[to[i]] > sz[son[u]]) son[u] = to[i];
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; id[u] = ++idd;
    if (son[u]) 
        dfs2(son[u], tp);
    for (int i = head[u]; i; i = nxt[i]) 
        if (to[i] != fa[u] && to[i] != son[u]) 
            dfs2(to[i], to[i]);
}
void update(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        sum[id[top[x]]]++, sum[id[x] + 1]--; // 区间覆盖
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    sum[id[x]]++, sum[id[y] + 1]--;
}
int da[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", da + i);
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs1(1, -1); dfs2(1, 1);
    for (int i = 1; i < n; i++) update(da[i], da[i + 1]);
    for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++) {
        if (i == da[1]) printf("%d\n", sum[id[i]]);
        else printf("%d\n", sum[id[i]] - 1);
    }
    return 0;
}