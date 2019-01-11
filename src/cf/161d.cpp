#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int dp[maxn][510];
int head[maxn];
struct node {
    int t, nxt;
}ve[maxn<<1];
int tot;
ll ans;
int n, k;
void add(int u, int v) {
    ve[tot] = (node){u, head[v]};
    head[v] = tot++;
    ve[tot] = (node){v, head[u]};
    head[u] = tot++;
}
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
    ans = 0;
}
void dfs(int u, int f) {
    dp[u][0] = 1;
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        node& tmp = ve[i];
        if (f == tmp.t) continue;
        dfs(tmp.t, u);
        for (int j = 0; j < k; j++) ans += 1LL * dp[u][k-j-1] * dp[tmp.t][j];
        for (int j = 1; j <= k; j++) dp[u][j] += dp[tmp.t][j-1];
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    int a, b;
    init();
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    dfs(1, -1);
    printf("%lld", ans);
    return 0;
}