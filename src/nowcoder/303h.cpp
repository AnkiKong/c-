#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
ll mod = 998244353;

inline ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n;
        ll a, b;
        ll ans = 1, sum;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &a, &b);
            sum = (qpow(2, a) + qpow(2, b) - 2 + mod) % mod;
            ans = ans * sum % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}