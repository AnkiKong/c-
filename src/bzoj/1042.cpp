#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5 + 100;
ll dp[maxn];
int cnt[4], cost[4];
ll ans;
void dfs(int res, int level, int sign) {
    if (level == 4) {
        ans += sign * dp[res];
        return;
    }
    dfs(res, level+1, sign);
    if (res >= (cnt[level]+1) * cost[level])
        dfs(res - (cnt[level]+1) * cost[level], level+1, -sign);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    for (int i = 0; i < 4; i++) scanf("%d", cost+i);
    dp[0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = cost[i]; j < maxn; j++) {
            dp[j] += dp[j-cost[i]];
        }
    }
    int T, s; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ans = 0;
        for (int i = 0; i < 4; i++) scanf("%d", cnt + i);
        scanf("%d", &s);
        dfs(s, 0, 1);
        printf("%lld\n", ans);
    }

    return 0;
}