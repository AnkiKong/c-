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
const int maxn=5e6+100;
const int mod=1000000007;
const int inv2=500000004;;
bool inp[maxn];
int p[448617], pCnt;
ll ph[maxn];
void init() {
    ph[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) p[pCnt++]=i, ph[i]=i-1;
        for (int j=0, t; j<pCnt && (t=p[j]*i)<maxn; j++) {
            inp[t]=1;
            if (i%p[j]==0) {
                ph[t]=ph[i]*p[j];
                break;
            } else {
                ph[t]=ph[i]*(p[j]-1);
            }
        }
    }
    for (int i=1; i<maxn; i++) ph[i]=(ph[i-1]+ph[i])%mod;
}
unordered_map<ll, int> mp;

int getAns(ll n) {
    if (n<maxn) return ph[n];
    if (mp.find(n)!=mp.end()) return mp[n];
    ll ans=n%mod*((n+1)%mod)%mod*inv2%mod;
    for (ll i=2, r; i<=n; i=r+1) {
        r=n/(n/i);
        ans=(ans-1LL*getAns(n/i)*(r-i+1)%mod)%mod;
    }
    ans=(ans+mod)%mod;
    return mp[n]=ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    ll n; scanf("%lld", &n);
    printf("%d\n", getAns(n));
    return 0;
}