#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=510;
const int mod=998244353;
char a[maxn], b[maxn];
ll dp[maxn][maxn][2];
ll A(int,int,int);
ll B(int,int,int);
ll A(int l, int r, int x) {
    if (l==r) return (a[l]=='0' || a[l]=='?') && (b[l]=='?' || b[l]==x+'0');
    if (b[l]!='?' && b[l]!=x+'0') return 0;
    if (a[l]=='0') return 0;
    return B(l+1, r, 0);
}
ll B(int l, int r, int x) {
    if (l>r) return 1;
    if (~dp[l][r][x]) return dp[l][r][x];
    if (l==r) return (a[l]=='0' || a[l]=='?') && (b[l]=='?' || b[l]==x+'0');
    ll ans=A(l, r, x);
    for (int i=l; i<r; i++) ans=(ans+B(l, i, 1)*A(i+1, r, x)%mod)%mod;
    return dp[l][r][x]=ans;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    // memset(dp, -1, sizeof(dp));
    scanf("%d%s%s", &n, a+1, b+1);
    // printf("%lld\n", A(1, n, 0));
    if (b[1]=='1') {
        printf("0");
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (a[i]!='1') dp[i][i][0]=1;
        if (a[i]!='0') dp[i][i][1]=1;
    }
    for (int l=1; l<=n; l++) {
        for (int i=1; i<=n-l; i++) {
            for (int j=i; j<i+l; j++) {
                ll tp=dp[i][j][1]*dp[j+1][i+l][0]%mod;
                if (b[j+1]!='0') dp[i][i+l][1]=(dp[i][i+l][1]+tp)%mod;
                if (b[j+1]!='1') dp[i][i+l][0]=(dp[i][i+l][0]+tp)%mod;
            }
        }
    }
    printf("%lld\n", dp[1][n][0]);
    return 0;
}