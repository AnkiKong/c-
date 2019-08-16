#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e7+10;
const int mod=998244353;
ll fac[maxn<<1], inv[maxn<<1];
int qpow(ll a, int b=mod-2) {
    a%=mod; ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
struct node {
    int t, p;
    bool operator < (const node& a) const {
        return t<a.t;
    } 
}atk[3100];
ll cnt[maxn], sum[maxn];
ll dp[2][maxn];
void init(int l) {
    l<<=1;
    dp[0][0]=fac[0]=cnt[0]=sum[0]=1;
    for (int i=1; i<=l; i++) fac[i]=fac[i-1]*i%mod;
    inv[l]=qpow(fac[l]);
    for (int i=l; i; i--) inv[i-1]=inv[i]*i%mod;
}
ll C(ll n, ll m) {
    if (n<m || n<0 || m<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int l, d, m; 
    cin >> l >> d >> m;
    init(l);
    for (int i=1; i<=l; i++){
        if (i>=d) cnt[i]=sum[i-d];
        else cnt[i]=0;
        sum[i]=(sum[i-1]+cnt[i])%mod;
    }
    for (int i=1; i<=m; i++) {
        cin >> atk[i].t >> atk[i].p;
    }
    sort(atk+1, atk+m+1);
    ll ans=cnt[l];
    dp[0][0]=1;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<i; j++) {
            ll p=atk[i].p-atk[j].p;
            ll t=atk[i].t-atk[j].t;
            dp[0][i]=(dp[0][i]+dp[1][j]*C(p-d*t+t-1, t-1)%mod)%mod;
            dp[1][i]=(dp[1][i]+dp[0][j]*C(p-d*t+t-1, t-1)%mod)%mod;
        }
    }
    for (int i=1; i<=m; i++) {
        ans=(ans+dp[0][i]*cnt[l-atk[i].p]%mod)%mod;
        ans=(ans-dp[1][i]*cnt[l-atk[i].p]%mod+mod)%mod;
    }
    cout << ans;
    return 0;
}