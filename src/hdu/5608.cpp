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
const int maxn=2e6+100;
const int mod=1e9+7;
int p[150000], mu[maxn], pCnt;
bool inp[maxn];
void init() {
    mu[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) {
            p[pCnt++]=i;
            mu[i]=-1;
        }
        ll t;
        for (int j=0; j<pCnt && (t=1LL*i*p[j])<maxn; j++) {
            inp[t]=1;
            if (i%p[j]==0) {
                mu[t]=0; break;
            }
            mu[t]=-mu[i];
        }
    }
    // for (int i=1; i<maxn; i++) mu[i]+=mu[i-1];
}
int f[maxn];
void getF() {
    for (ll i=1; i<maxn; i++) {
        ll nw=(i*i-3*i+2)%mod;
        for (int j=i, cnt=1; j<maxn; j+=i, cnt++) {
            f[j]+=nw*mu[cnt];
            if (f[j]>=mod)f[j]-=mod;
            else if (f[j]<0) f[j]+=mod;
        }
    }
    for (int i=1; i<maxn; i++) {
        f[i]+=f[i-1];
        if (f[i]>mod)f[i]-=mod;
    }
}
ll inv3, inv6, inv2;
unordered_map<ll, int> mp;
ll sum(ll n) {
    if (n<maxn) return f[n];
    if (mp.find(n)!=mp.end()) return mp[n];
    ll nxt, ans, i=2;
    ans=(n*(n+1)%mod*(2*n+1)%mod*inv6%mod-3*n%mod*(n+1)%mod*inv2%mod+2*n%mod)%mod;
    for (; i<=n; i=nxt+1) {
        nxt=n/(n/i);
        ans=(ans-sum(n/i)*(nxt-i+1)%mod)%mod;
    }
    return mp[n]=(ans+mod)%mod;
}
ll qpow(ll a, ll b) {
    a%=mod; ll ans=1;
    for (; b; a=a*a%mod, b>>=1) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
ll inv(ll a) {
    return qpow(a, mod-2);
}
ll cal(ll a) {
    return a*(a-1)%mod*(a-2)*inv3%mod;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init(); getF();
    // printf("%d\n\n", pCnt);
    inv3=inv(3); inv6=inv(6); inv2=inv(2);
    int T; scanf("%d", &T);
    // auto cal = [](ll a) {
    //     return a*(a-1)%mod*(a-2)*inv3%mod;
    // };
    for (int TT = 1; TT <= T; TT++) {
        ll n; scanf("%lld", &n);
        
        printf("%lld\n", sum(n));
    }
    return 0;
}