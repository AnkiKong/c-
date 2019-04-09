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
const int mod=1e9+9;
ll w;
void exgcd(ll a, ll b, ll& d, ll&x, ll& y) {
    if (!b) {
        d = a, x = 1, y = 0;
    } else {
        exgcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}
ll inv(ll a, ll mod) {
    ll x, y, d;
    exgcd(a, mod, d, x, y);
    return (x%mod+mod)%mod;
}
ll qpow(ll a, ll b, ll md) {
    ll ans=1;
    for (a%=md; b; b>>=1, a=a*a%md) {
        if (b&1) ans=ans*a%md;
    }
    return ans;
}
struct node {
    ll p, d;
};
node mul(node a, node b, ll md) {
    node ans;
    ans.p=(a.p*b.p%md + a.d*b.d%md*w%md)%md;
    ans.d=(a.p*b.d%md + a.d*b.p%md)%md;
    return ans;
}
node qpow(node a, ll b, ll md) {
    node ans=node{1, 0};
    for (; b; b>>=1, a=mul(a, a, md)) {
        if (b&1) ans=mul(ans, a, md);
    }
    return ans;
}
ll solve(ll x, ll md) {
    if (md==2) return 1;
    if (qpow(x, (md-1)>>1, md)+1==md) return -1;
    ll a, t;
    for (a=1; a<md; a++) {
        t=a*a - x;
        w=(t+md)%md;
        if (qpow(w, (md-1)>>1, md)+1==md) break;
    }
    node tmp=node{a, 1};
    tmp=qpow(tmp, (md+1)>>1, md);
    return tmp.p;
    // sqrt(x)==tmp.p(%mod)
}
ll invSqrt5, r1, r2;
void init() {
    ll tmp=solve(5, mod);
    ll inv5=inv(5, mod);
    invSqrt5=(tmp*inv5)%mod;
    ll inv2=inv(2, mod);
    r1=((tmp+1)*inv2%mod)%mod;
    r2=(-tmp+1+mod)%mod*inv2%mod;
}

ll c[100005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ll n, k; scanf("%lld%lld", &n, &k);
        c[0]=1;
        for (int i=1; i<=k; i++) {
            ll x=inv(i, mod);
            c[i]=c[i-1]*x%mod*(k+1-i)%mod;
        }
        ll ans=0;
        for (int i=k, ty=1; ~i; i--, ty=-ty) {
            ll t1=c[i]*ty, t2;
            ll x=qpow(r1, i, 1LL*mod)*qpow(r2, k-i, 1LL*mod)%mod;
            if (x==1) t2=n%mod;
            else t2=x*(qpow(x, n, 1LL*mod)-1)%mod, t2=t2*qpow(x-1, mod-2LL, mod*1LL)%mod;
            ans=(ans+t1*t2%mod)%mod;
        }
        ans=(ans+mod)%mod;
        ans=ans*invSqrt5%mod;
        printf("%lld\n", ans);
    }
    return 0;
}