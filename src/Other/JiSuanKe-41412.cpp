#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=4000;
const int mod=1000000007;
ll F[maxn], invF[maxn];
int qpow(ll a, int b=mod-2) {
    a%=mod; ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
int n;
int dfs(int level, int val, int sum, int mul, int cnt, ll nwDiv) {
    if (level>n) {
        if (sum==mul) {
            return F[n]*nwDiv%mod*invF[cnt]%mod;
        } else {
            return 0;
        }
    }
    if (mul==sum+n-level) return F[n]*nwDiv%mod*invF[n-level]%mod*invF[cnt]%mod;
    if (mul>sum+n-level) return 0;
    if (val>n) return 0;
    if (mul*val>sum+val+(n-level)) return 0;
    int ans=0;
    ans+=dfs(level+1, val, sum+val, mul*val, cnt+1, nwDiv);
    ans+=dfs(level, val+1, sum, mul, 0, nwDiv*invF[cnt]%mod);
    return ans%mod;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    F[0]=1;
    for (int i=1; i<maxn; i++) F[i]=F[i-1]*i%mod;
    invF[maxn-1]=qpow(F[maxn-1]);
    for (int i=maxn-2; i>0; i--) invF[i]=invF[i+1]*(i+1)%mod;
    invF[0]=1;
    // cout << invF[2]*2%mod << " " << invF[3]*3*2%mod << "\n";
    int t; cin >> t;
    for (; t--; ) {
        cin >> n;
        cout << dfs(0, 2, 0, 1, 0, 1) << "\n";
    }
    return 0;
}