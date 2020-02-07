#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5 * 6010;
int dp[maxn];
int a[6010], b[6010], c[6010];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i <= 5 * 6000; i++) {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
        if (!a[i]) a[i] = inf;
        if (!b[i]) b[i] = inf;
        if (!c[i]) c[i] = inf;
        sum += min(a[i], min(b[i], c[i]));
        for (int j = sum; j >= 0; j--) {
            int tmp = inf;
            if (j >= a[i]) tmp = min(tmp, dp[j - a[i]]);
            tmp = min(tmp, dp[j] + b[i]);
            if (j >= c[i]) tmp = min(tmp, dp[j-c[i]] + c[i]);
            dp[j] = tmp;
        }
    }
    int ans = inf;
    for (int i = 0; i <= 5 * 6000; i++) {
        ans = min(ans, max(i, dp[i]));
    }
    printf("%d", ans);
    return 0;
}