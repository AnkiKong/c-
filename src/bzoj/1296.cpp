#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
char str[60][3000];
int dp[60][3000];
int fcnt[60][60][60];
int n, m, t;
int cal(int k, int f, int t) {
    // 第k块木板，从区间f到区间t，只涂一次，最多可以正确涂几个区块
    int cnt = 0;
    for (int i = f; i <= t; i++) {
        cnt += str[k][i] - '0';
    }
    return max(cnt, t - f - cnt + 1);
}
void cal2(int k) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= min(i, t); j++) {
            for (int q = i; q > 0; q--) {
                // 第k块木板，1-i区块，涂j次，最多能正确填涂fcnt[k][i][j]块
                fcnt[k][i][j] = max(fcnt[k][i][j], fcnt[k][q-1][j-1] + cal(k, q, i));
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        cal2(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            for (int k = 0; k <= j; k++) {
                // 二维背包，取i块木板，涂j次
                dp[i][j] = max(dp[i][j], dp[i-1][j-k] + fcnt[i][m][k]);
            }
        }
    }
    printf("%d\n", dp[n][t]);
    return 0;
}