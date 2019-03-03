#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
const int mod=1000000007;
int dp[maxn][3];
int n, m, k;
int cal(int lit) {
    dp[0][0] = dp[0][1] = 0; dp[0][2] = 1;
    for (int i = 1, sum; i <= n; i++) {
        sum = (0LL + dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod;
        dp[i][2] = sum;
        if (i <= lit) dp[i][0] = sum;
        else dp[i][0] = ((sum - dp[i-lit-1][1] - dp[i-lit-1][2]) % mod + mod) % mod;
        if (i <= k) dp[i][1] = sum;
        else dp[i][1] = ((sum - dp[i-k-1][0] - dp[i-k-1][2]) % mod + mod) % mod;
    }
    return (0LL + dp[n][0] + dp[n][1] + dp[n][2]) % mod;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (; ~scanf("%d%d%d", &n, &m, &k); ) {
        printf("%d\n", ((cal(n) - cal(m-1)) % mod + mod) % mod);
    }
    return 0;
}