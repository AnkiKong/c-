#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
const int mod = 9999973;
ll dp[110][110][110];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k + j <= m; k++) {
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % mod;
                dp[i+1][j+1][k] = (dp[i+1][j+1][k] + dp[i][j][k] * (m - j - k)) % mod;
                if (j) dp[i+1][j-1][k+1] = (dp[i+1][j-1][k+1] + dp[i][j][k] * j) % mod;
                dp[i+1][j+2][k] = (dp[i+1][j+2][k] + dp[i][j][k] * (m - j - k) * (m - j - k - 1) / 2) % mod;
                if (j) dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k] * j * (m - j - k)) % mod;
                if (j>1) dp[i+1][j-2][k+2] = (dp[i+1][j-2][k+2] + dp[i][j][k] * j * (j-1) / 2) % mod;
                
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j + i <= m; j++) {
            ans = (ans + dp[n][i][j]) % mod;
        }
    }
    printf("%lld", ans);
    return 0;
}