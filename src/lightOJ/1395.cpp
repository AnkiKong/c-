#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=110;
double dp[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        printf("Case %d: ", TT);
        memset(dp, 0, sizeof(dp));
        int n, k, tmp; scanf("%d%d", &n, &k);
        int out = 0, nout = 0;
        double sumOut = 0, sumNout = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (tmp > 0) out++, sumOut += tmp;
            else nout++, sumNout -= tmp;
        }
        if (!out) {
            printf("-1\n");
        } else {
            k = min(k, nout);
            dp[k] = (sumOut + (nout ? sumNout * (nout - k) / nout : 0.0)) / out;
            for (int i = k - 1; i >= 0; i--) {
                dp[i] = (sumOut + (dp[i + 1] + sumNout / nout) * (nout - i)) / (n - i);
            }
            printf("%.10f\n", dp[0]);
        }
    }
    return 0;
}