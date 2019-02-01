#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5000;
int dp[2][maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, p;
    scanf("%d%d", &n, &p);
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i&1][j] = (dp[i&1][j-1] + dp[(i-1)&1][i-j]) % p;
        }
    }
    printf("%d", dp[n&1][n] * 2 % p);
    return 0;
}