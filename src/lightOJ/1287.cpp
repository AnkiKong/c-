#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const double eps = 1e-6;
const int maxn=16;
double dp[maxn][1 << maxn];
double mp[maxn][maxn];
bool vis[maxn][1 << maxn];
void init() {
    memset(dp, 0, sizeof(dp));
    memset(mp, 0, sizeof(mp));
    memset(vis, 0, sizeof(vis));
}
int n, m;
int dfs(int u, int state) {
    if (state == (1<<n)-1) {
        dp[u][state] = 0;
        return 1;
    }
    if (vis[u][state]) return dp[u][state] > eps;
    int cnt = 0;
    dp[u][state] = 5;
    vis[u][state] = true;
    for (int i = 0; i < n; i++) {
        if (mp[u][i] && dfs(i, state | (1<<i)) && !(state & (1<<i))) {
            dp[u][state] += mp[u][i] + dp[i][state | (1<<i)];
            cnt++;
        }
    }
    if (cnt) {
        dp[u][state] /= cnt;
        return 1;
    }
    dp[u][state] = 0;
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &n, &m);
        init();
        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            mp[a][b] = mp[b][a] = c;
        }
        dfs(0, 1);
        printf("Case %d: %.10f\n", TT, dp[0][1]);
    }
    return 0;
}