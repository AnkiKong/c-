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
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i < maxn; i++) {
        double sum = 0, cnt = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                cnt++, sum += dp[j];
                if (j * j != i) {
                    cnt++, sum += dp[i/j];
                }
            }
        }
        dp[i] = (sum + cnt) / (cnt - 1);
    }
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %.9f\n", TT, dp[n]);
    }
    return 0;
}