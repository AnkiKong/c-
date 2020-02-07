#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100 * 100 + 100;
double dp[maxn];
int val[110];
double cost[110];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        
        double tot; int n, sum = 0; 
        scanf("%lf%d", &tot, &n);
        tot = 1 - tot;
        for (int i = 0; i < n; i++) {
            scanf("%d%lf", val + i, cost + i);
            sum += val[i]; cost[i] = 1 - cost[i];
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= val[i]; j--) {
                dp[j] = max(dp[j], dp[j - val[i]] * cost[i]);
            }
        }
        int ans = 0;
        for (int i = sum; i; i--) {
            if (dp[i] > tot) {
                ans = i;break;
            }
        }
        printf("Case %d: %d\n", TT, ans);
    }
    return 0;
}