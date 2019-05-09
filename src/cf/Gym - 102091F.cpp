#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
const int mod=1e9+7;
int qpow(ll a, int b) {
    ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
int inv2;
int getSum(ll a) {
    a%=mod;
    return a*(a+1)%mod*inv2%mod;
}
int dv[30];
int dp[30];
int dfs(int pos, bool lit) {
    if (pos<0) return 1;
    if (!lit && ~dp[pos]) return dp[pos];
    int up=lit?dv[pos]:6;
    int ans=0;
    for (ll i=0; i<=up; i++) {
        ans=(ans+(i+1)*dfs(pos-1, lit && i==dv[pos])%mod)%mod;
    }
    if (!lit) dp[pos]=ans;
    return ans;
}
int getAns(ll a) {
    int pos=0;
    memset(dp, -1, sizeof(dp));
    for (; a; ) {
        dv[pos++]=a%7;
        a/=7;
    }
    return dfs(pos-1, 1);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // IOS;
    inv2=qpow(2, mod-2);
    ll n;
    int T; 
    // cin >> T;
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        // cin >> n;
        scanf("%lld", &n);
        getAns(n);
        // cout << "Case " << TT << ": ";
        // cout << ((getSum(n+1)-getAns(n))%mod+mod)%mod << "\n";
        printf("Case %d: %d\n", TT, ((getSum(n+1)-getAns(n))%mod+mod)%mod);
    }
    return 0;
}