#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5e5+100;
int head[maxn];
struct node {
    int t, w, nxt;
};
node ve[maxn<<1];
ll dp[maxn];
int cnt;
int n, root;
ll ans;
void add(int a, int b, int c) {
    ve[cnt] = (node) {a, c, head[b]}; head[b] = cnt++;
    ve[cnt] = (node) {b, c, head[a]}; head[a] = cnt++;
}
void dfs(int f, int u) {
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        if (ve[i].t == f) continue;
        dfs(u, ve[i].t);
        dp[u] = max(dp[u], dp[ve[i].t] + ve[i].w);
    }
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        if (ve[i].t == f) continue;
        ans += dp[u] - dp[ve[i].t] - ve[i].w;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &root);
    int a, b, c;
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    dfs(-1, root);
    printf("%lld", ans);
    return 0;
}