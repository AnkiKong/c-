#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int maxn=300*600;
int dp[maxn];
int da[400];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int t; cin >> t;
    for (int n; t--; ) {
        cin >> n;
        int sum=0;
        for (int i=1; i<=n; i++) {
            cin >> da[i];
            sum+=da[i];
        }
        sort(da+1, da+1+n);
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        for (int i=1; i<=n; i++) {
            for (int j=sum; j>=da[i]; j--) {
                dp[j]+=dp[j-da[i]];
                dp[j]%=mod;
            }
        }
        int ans=0;
        for (int i=1; i<=n; i++) {
            for (int j=da[i]; j<=sum; j++) {
                dp[j]=(dp[j]-dp[j-da[i]]+mod)%mod;
            }
            for (int j=max(0, (sum+1)/2-da[i]); j*2<=sum-da[i]; j++) {
                ans=(ans+dp[j])%mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}