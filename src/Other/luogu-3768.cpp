#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e6+100;
ll mod;
int pri[maxn], phi[maxn];
ll g[maxn];
ll inv4, inv6;
int tot;
bool inp[maxn];
void init() {
    phi[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) pri[tot++]=i, phi[i]=i-1;
        for (int j=0; j<tot && 1LL*i*pri[j]<maxn; j++) {
            inp[i*pri[j]]=1;
            if (i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }
        }
    }
    for (ll i=1; i<maxn; i++) {
        g[i]=(g[i-1]+i*i%mod*phi[i]%mod)%mod;
    }
}
ll qpow(ll a, int b=mod-2) {
    ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
ll cal2(ll n) {
    n%=mod;
    return n*(n+1)%mod*(2*n+1)%mod*inv6;
}
ll cal3(ll n) {
    n%=mod;
    return n*n%mod*(n+1)%mod*(n+1)%mod*inv4%mod;
}
unordered_map<ll,ll> vis;
ll G(ll n) {
    if (n<maxn) return g[n];
    if (vis.count(n)) return vis[n];
    ll res=cal3(n);
    for (ll i=2, r, val; i<=n; i=r+1) {
        val=n/i; r=n/val;
        res=(res-(cal2(r)-cal2(i-1)+mod)%mod*G(val)%mod+mod)%mod;
    }
    return vis[n]=res;
}
inline ll sqr(ll a) {
    a%=mod; return a*a%mod;
}
ll solve(ll n) {
    ll res=0;
    for (ll i=1, r, val; i<=n; i=r+1) {
        val=n/i; r=n/val;
        res=(res+sqr(val)*sqr(val+1)%mod*(G(r)-G(i-1)+mod)%mod*inv4%mod)%mod;
    }
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n;
    cin >> mod >> n;
    inv4=qpow(4), inv6=qpow(6);
    init();
    cout << solve(n);
    return 0;
}