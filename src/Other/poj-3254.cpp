#include <cstdio>
#include <cstring>
// #include 
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
const int mod = 1e8;
int dp[13][(1<<12)+10];
int mp[13];
int check(int x, int i) {
    if ((x & mp[i]) != x) return 0;
    if ((x & (x<<1)) != 0) return 0;
    return 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    int a;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            mp[i] = (mp[i]<<1) + a;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1<<m); j++) {
            if (!check(j, i)) continue;
            for (int k = 0; k < (1<<m); k++) {
                if (!check(k, i-1) || j&k) continue;
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << m; i++) {
        ans = (ans + dp[n][i]) % mod;
    }
    printf("%d", ans);
    return 0;
}