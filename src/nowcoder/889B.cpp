#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
// const int maxn=;
ll qpow(ll a, int b=mod-2) {
    a%=mod; ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS; int t; cin >> t;
    for (ll b, c; t--; ) {
        cin >> b >> c;
        ll deta=(b*b%mod-4*c%mod+mod)%mod;
        ll _deta=qpow(deta, (mod+1)/4);
        ll x=(b+_deta)%mod*qpow(2)%mod;
        ll y=(b-x+mod)%mod;
        if ((x*y)%mod!=c) printf("-1 -1\n");
        else printf("%lld %lld\n", min(x, y), max(x, y));
    }
    return 0;
}