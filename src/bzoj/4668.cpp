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
const int maxn=6e5;
int fa[maxn], sz[maxn], w[maxn];
int fin(int x) {
    for ( ; x != fa[x]; x = fa[x]);
    return x;
}
int dep[maxn];
void dfs(int x) {
    if (fa[x] == x) return;
    dfs(fa[x]);
    dep[x] = dep[fa[x]] + 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int TT = 0;
    int n, m, ans = 0; scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) sz[i] = 1, fa[i] = i;
    for (int i = 0, op, a, b, ta, tb; i < m; i++) {
        scanf("%d%d%d", &op, &a, &b);
        a ^= ans, b ^= ans;
        if (op == 0) {
            a = fin(a), b = fin(b);
            ++TT;
            if (a == b) continue;
            if (sz[a] > sz[b]) swap(a, b);
            fa[a] = b, sz[b] += sz[a], w[a] = TT;
        } else {
            ta = fin(a), tb = fin(b);
            if (ta != tb) printf("0\n"), ans = 0;
            else {
                dfs(a); dfs(b);
                ans = 0;
                if (dep[a] < dep[b]) swap(a, b);
                while (dep[a] > dep[b]) ans = max(ans, w[a]), a = fa[a];
                while (a != b) ans = max(ans, max(w[a], w[b])), a = fa[a], b = fa[b];
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}