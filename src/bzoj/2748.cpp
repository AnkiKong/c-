#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1010;
int dp[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, bg, mx;
    scanf("%d%d%d", &n, &bg, &mx);
    int a;
    dp[bg][0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 0; j <= mx; j++) {
            if (j + a <= mx) dp[j+a][i] |= dp[j][i-1];
            if (j >= a) dp[j-a][i] |= dp[j][i-1];
        }
    }
    for (int i = mx; i >= 0; i--) {
        if (dp[i][n]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}