#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e4+100;
int a[maxn], dp[maxn];
int n; 
int check() {
    int flag = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = a[i-1] - dp[i-1] - dp[i-2];
        if (dp[i] < 0) {
            flag = 0; break;
        }
    }
    return flag && (dp[n] + dp[n-1] == a[n]);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int ans = 0;
    if (a[1] == 0) {
        dp[1] = dp[2] = 0;
        ans += check();
    } else if (a[1] == 1) {
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        ans += check();
        memset(dp, 0, sizeof(dp));
        dp[1] = 0, dp[2] = 1;
        ans += check();
    } else {
        memset(dp, 0, sizeof(dp));
        dp[1] = dp[2] = 1;
        ans += check();
    }
    printf("%d", ans);
    return 0;
}