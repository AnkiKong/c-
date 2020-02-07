#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e4;
int s[maxn];
int dp[2][maxn];
int n, m;
const int mod = 10007;
int check(int mid) {
    int cnt = 0,  last = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] - s[last] > mid) {
            cnt++; last = i - 1;
        }
    }
    return cnt <= m;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int l = 0, r;
    for (int i = 1; i <= n; i++) {
        scanf("%d", s + i);
        l = max(l, s[i]);
        s[i] += s[i-1];
    }
    r = s[n];
    int ans1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) ans1 = mid, r = mid - 1;
        else l = mid + 1;
    }
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 1; i <= m + 1; i++) {
        int p = i - 2, t = 0;
        for (int j = i; j <= n; j++) {
            t = (t + dp[(i+1)&1][j-1]) % mod;
            while (s[j] - s[p+1] >ans1) t = (t - dp[(i+1)&1][++p]) % mod;
            dp[i&1][j] = (mod + t) % mod;
        }
        ans = (ans + dp[i&1][n]) % mod;
    }
    printf("%d %d", ans1, ans);
    return 0;
}