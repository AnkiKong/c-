#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
char str[maxn];
int dp[5][4][4][4][4];
int cal(int a, int b, int c) {
    int tmp = 1;
    if (a != 0 && a != b && a != c) tmp++;
    if (b != 0 && b != c) tmp++;
    return tmp;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d%s", &n, str);
    dp[0][0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        int now = str[i] == 'M' ? 1 : (str[i] == 'B' ? 2 : 3);
        int ni = i % 4, nxti = (i + 1) % 4, tmp;
        for (int a1 = 0; a1 < 4; a1++) {
            for (int a2 = 0; a2 < 4; a2++) {
                for (int b1 = 0; b1 < 4; b1++) {
                    for (int b2 = 0; b2 < 4; b2++) {
                        if (dp[ni][a1][a2][b1][b2] == -1) continue;
                        tmp = cal(a1, a2, now);
                        dp[nxti][a2][now][b1][b2] = max(dp[nxti][a2][now][b1][b2], dp[ni][a1][a2][b1][b2] + tmp);
                        tmp = cal(b1, b2, now);
                        dp[nxti][a1][a2][b2][now] = max(dp[nxti][a1][a2][b2][now], dp[ni][a1][a2][b1][b2] + tmp);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int a1 = 0; a1 < 4; a1++) {
            for (int a2 = 0; a2 < 4; a2++) {
                for (int b1 = 0; b1 < 4; b1++) {
                    for (int b2 = 0; b2 < 4; b2++) {
                        ans = max(ans, dp[i][a1][a2][b1][b2]);
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}