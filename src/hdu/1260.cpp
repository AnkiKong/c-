#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=3000;
int dp[maxn][2];
int a[maxn];
int a2[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", a2 + i);
        }
        dp[1][0] = dp[1][1] = a[1];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
            dp[i][1] = min(dp[i-2][0], dp[i-2][1]) + a2[i];
        }
        int ti = 8 * 60 * 60 + min(dp[n][0], dp[n][1]);
        int h = ti / 3600, m = ti / 60 % 60, tii = ti % 60;
        printf("%02d:%02d:%02d %s\n", h % 12, m, tii, h > 12 ? "pm" : "am");
        // printf("%d\n", min(dp[n][0], dp[n][1]));
    }
    return 0;
}