#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
int cal(int n) {
    return n * (n - 1) / 2;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int t, d; scanf("%d%d", &t, &d);
        if (t & 1) {
            printf("Case %d: 0\n", TT);
            continue;
        }
        double ans = 1.0;
        for (int i = t + 1; i > 1; i -= 2) {
            ans *= 1.0 * cal(i - 1) / cal(i);
        }
        printf("Case %d: %.9f\n", TT, ans);
    }
    return 0;
}