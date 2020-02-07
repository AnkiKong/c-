#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e6+100;
const int mod=1e9+7;
ll g[maxn];
int pri[maxn], tot;
bool inp[maxn];
void init() {
    g[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) pri[tot++]=i, g[i]=(1LL*i*i-1)%mod;
        for (int j=0, P; j<tot && 1LL*i*(P=pri[j])<maxn; j++) {
            inp[i*P]=1;
            if (i%P==0) {
                g[i*P]=g[i]*P%mod*P%mod;
                break;
            } else {
                g[i*P]=g[i]*g[P]%mod;
            }
        }
    }
    for (int i=1; i<maxn; i++) {
        g[i]=(g[i-1]+g[i])%mod;
    }
}
int qpow(ll a, int b=mod-2) {
    ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
ll cal(ll a, int k, int k2) {
    if (a==1) return (k2-1+mod)%mod;
    return a*a%mod*(qpow(a, k-1)-1+mod)%mod*qpow(a-1)%mod;
}
unordered_map<ll, ll> vis;
char K[int(1e5+100)];
ll G(ll a) {
    if (a<maxn) return g[a];
    if (vis.count(a)) return vis[a];
    ll res=a*(a+1)%mod*(2*a%mod+1)%mod*qpow(6)%mod;
    for (ll i=2, r, val; i<=a; i=r+1) {
        val=a/i; r=a/val;
        res=(res-(r-i+1)*G(val)%mod+mod)%mod;
        // res=(res+mod)%mod;
    }
    return vis[a]=res;
}
ll solve(ll n) {
    ll k=0, k2=0;
    for (int i=0; K[i]; i++) {
        k=(K[i]-'0'+k*10)%(mod-1);
        k2=(K[i]-'0'+k2*10)%mod;
    }
    ll res=0;
    for (ll i=1, r, val; i<=n; i=r+1) {
        val=n/i; r=n/val;
        res+=(G(r)-G(i-1))%mod*cal(val, k, k2)%mod;
        res%=mod;
    }
    return (res+mod)%mod;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    init();
    int t; ll n;
    // cin >> t; 
    scanf("%d", &t);
    for (; t--; ) {
        // cin >> n >> K;
        scanf("%lld%s", &n, K);
        printf("%lld\n", solve(n));
    }
    return 0;
}