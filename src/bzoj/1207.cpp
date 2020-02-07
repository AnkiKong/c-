#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5;
int ti[maxn], loc[maxn][2];
int dp[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", ti+i, loc[i], loc[i]+1);
    }
    for (int i = 0; i < m; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (abs(loc[i][0] - loc[j][0]) + abs(loc[i][1]-loc[j][1]) <= ti[i] - ti[j]) 
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}