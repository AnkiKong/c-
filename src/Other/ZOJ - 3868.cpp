#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int maxn=1e6+100;
int cnt[maxn], dp[maxn];
int qpow(ll a, int b) {
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
    IOS;
    int t; 
    cin >> t;
    for (int n, k, mx; t--; ) {
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        mx=0;
        for (int i=0, a; i<n; i++) {
            cin >> a;
            cnt[a]++;
            mx=max(mx, a);
        }
        int ans=0;
        for (int i=mx; i; i--) {
            int num=0;
            for (int j=i; j<=mx; j+=i) {
                num+=cnt[j];
                dp[i]=(dp[i]-dp[j])%mod;
            }
            dp[i]=(dp[i]+mod+qpow(2, num)-1)%mod;
            ans=(ans+1LL*dp[i]*qpow(i, k))%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}