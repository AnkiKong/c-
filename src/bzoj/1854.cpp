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
const int maxn=1e6+100;
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
bool vis[10101];
int fa[maxn];
int dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        if (!fa[to[i]] || dfs(fa[to[i]])) {
            fa[to[i]] = u;
            return 1;
        }
    }
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, i); add(b, i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (!dfs(i)) break;
        ans = i;
    }
    printf("%d\n", ans);
    return 0;
}