#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200;
double dp[maxn];
double data[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lf", dp + i);
        }
        
        for (int i = n - 1; i; i--) {
            int k = min(6, n - i);
            for (int j = 1; j <= k; j++) {
                dp[i] += dp[i + j] / k;
            }
        }
        printf("Case %d: %.8f\n", TT, dp[1]);
    }
    return 0;
}