#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
const int mod = 1e9 + 7;
ll qpow (ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = (1LL * a * a) % mod) {
        if (b & 1) ans = 1LL * ans * a % mod;
    }
    return ans;
}
ll inv(ll a) {
    return qpow(a, mod - 2);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    ll a = 1, b = 1;
    ll aa, bb;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &aa, &bb);
        a = (bb-aa) * a % mod, b = bb * b % mod;
    }
    a = (b - a + mod + mod) % mod;
    printf("%lld\n", a * inv(b) % mod);
    return 0;
}