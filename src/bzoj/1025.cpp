#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1010;
bool isp[maxn];
int pri[maxn];
ll dp[maxn][maxn];
int cnt;
void init() {
    cnt = 1;
    for (int i = 2; i < maxn; i++) {
        if (isp[i] == 0) pri[cnt++] = i;
        for (int j = i * i; j < maxn; j += i) isp[j] = 1;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int n; scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i < cnt; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = dp[i-1][j];
        for (ll j = pri[i]; j <= n; j *= pri[i]) {
            for (int k = j; k <= n; k++) {
                dp[i][k] += dp[i-1][k-j]; 
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans += dp[cnt-1][i];
    printf("%lld\n", ans);
    return 0;
}