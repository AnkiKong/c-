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
        ll a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        ll ans = a * (k / 2 + k % 2) - b * (k / 2);
        printf("%lld\n", ans);
    }
    return 0;
}