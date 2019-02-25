#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5100;
const int mod = 1e8;
char s1[maxn], s2[maxn];
int dp[2][maxn], cnt[2][maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s", s1 + 1, s2 + 1);
    int len1 = strlen(s1 + 1) - 1, len2 = strlen(s2 + 1) - 1;
    for (int i = 0; i < maxn; i++) cnt[0][i] = 1;
    for (int i = 1; i <= len1; i++) {
        cnt[i&1][0] = 1;
        for (int j = 1; j <= len2; j++) {
            cnt[i & 1][j] = 0; dp[i&1][j] = 0;
            if (s1[i] == s2[j]) {
                dp[i&1][j] = dp[(i+1)&1][j-1] + 1;
                cnt[i&1][j] = cnt[(i+1)&1][j-1];
            }
            if (dp[(i+1)&1][j] > dp[i&1][j]) {
                dp[i&1][j] = dp[(i+1)&1][j];
            }
            if (dp[i&1][j-1] > dp[i&1][j]) {
                dp[i&1][j] = dp[i&1][j-1];
            }

            if (dp[(i+1)&1][j] == dp[i&1][j]) {
                cnt[i&1][j] += cnt[(i+1)&1][j];
            }
            if (dp[i&1][j-1] == dp[i&1][j]) {
                cnt[i&1][j] += cnt[i&1][j-1];
            }
            if (dp[i&1][j] == dp[(i+1)&1][j-1]) {
                cnt[i&1][j] -= cnt[(i+1)&1][j-1];
            }
            cnt[i&1][j] = (cnt[i&1][j] + mod) % mod;
        }
    }
    printf("%d\n%d\n", dp[len1&1][len2], cnt[len1&1][len2]);
    return 0;
}