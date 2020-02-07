#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
const ll mod=1000000007;
ll qpow(ll a, ll b) {
    a %= mod;
    ll ans = 1;
    for (; b; b>>=1, a = a*a%mod) {
        if (b&1) ans = ans * a % mod;
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
        ll n, m; scanf(lld lld, &n, &m);
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + qpow(n, __gcd(1LL*i, m))) % mod;
        }
        if (m&1) {
            ans = (ans + m*qpow(n, (m+1)/2)) % mod;
        } else {
            ans = (ans + m/2*(qpow(n, m/2)+qpow(n, (m-2)/2+2))%mod) % mod;
        }
        printf("Case #%d: ", TT);
        printf(lld "\n", ans * qpow(2*m, mod-2) % mod);
    }
    return 0;
}