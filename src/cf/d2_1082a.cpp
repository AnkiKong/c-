#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ll n, d, x, y;
        scanf("%lld%lld%lld%lld", &n, &x, &y, &d);
        if (abs(x - y) % d == 0) {
            printf("%lld\n", abs(x - y) / d);
        } else {
            ll ans = -1;
            if ((y - 1) % d == 0) {
                ans = (y - 1) / d + (x - 1) / d + ((x - 1) % d != 0);
            }
            if ((n - y) % d == 0) {
                ll anst = (n - y) / d + (n - x) / d + ((n - x) % d != 0);
                if (ans != -1) ans = min(anst, ans);
                else ans = anst;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}