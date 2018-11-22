#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e4 + 100;
int dp[maxn];
int cost[maxn];
int val[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n, m; scanf("%d%d", &n, &m);
        m -= n;
        int q; scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", val + i, cost + i);
        }
        memset(dp, 0x3f3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < q; i++) {
            for (int j = cost[i]; j <= m; j++) {
                dp[j] = min(dp[j - cost[i]] + val[i], dp[j]);
            }
        }
        if (dp[m] != 0x3f3f3f3f) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
        } else {
            printf("This is impossible.\n");
        }
    }
    return 0;
}