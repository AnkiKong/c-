#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5;
struct node {
    int u, nxt;
} v[maxn];
int head[maxn];
int da[maxn];
int n, s, cnt = 1;
int ans;
void add(int a, int b) {
    v[cnt] = (node) {b, head[a]}; head[a] = cnt++;
}
int f[maxn][20], g[maxn][20];
void dfs(int u, int fa) {
    f[u][0] = fa; g[u][0] = da[u];
    for (int i = 1; i < 20; i++) {
        f[u][i] = f[f[u][i-1]][i-1];
        g[u][i] = g[f[u][i-1]][i-1] + g[u][i-1];
    }
    int nowu = u, res = s;
    for (int i = 19; i >= 0; i--) {
        if (f[nowu][i] && g[nowu][i] <= res) res -= g[nowu][i], nowu = f[nowu][i];
    }
    if (!res) ans++;
    for (int i = head[u]; i; i = v[i].nxt) {
        if (v[i].u != fa) dfs(v[i].u, u);
    }
}
bool nfa[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++) scanf("%d", da + i);
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b); nfa[b] = 1;
    }
    int faa;
    for (int i = 1; i <= n; i++) if (!nfa[i]) faa = i;
    dfs(faa, -1);
    printf("%d", ans);
    return 0;
}