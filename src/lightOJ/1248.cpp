#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
double dp[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n;
        scanf("%d", &n);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + 1.0 * n / (n - i + 1);
        }
        printf("Case %d: %.10f\n", TT, dp[n]);
    }
    return 0;
}