#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
int dp[200][200][30][30];
const int mod = 12345678;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    dp[0][0][0][0] = 1;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int p = 0; p <= k; p++) {
                for (int q = 0; q <= k; q++) {
                    dp[i][j+1][max(0, p-1)][q+1] = (dp[i][j+1][max(0, p-1)][q+1] + dp[i][j][p][q]) % mod;
                    dp[i+1][j][p+1][max(0, q-1)] = (dp[i+1][j][p+1][max(0, q-1)] + dp[i][j][p][q]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            ans = (ans + dp[n][m][i][j]) % mod;
        }
    }

    printf("%d\n", ans);
    return 0;
}