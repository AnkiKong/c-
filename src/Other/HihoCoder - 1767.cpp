#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2100;
int a[maxn], b[maxn];
int dp[maxn][maxn][2];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", a+i);
    }
    scanf("%d", &m);
    for (int j=1; j<=m; j++) {
        scanf("%d", b+j);
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        int mlen1=0, mlen0=0;
        for (int j=1; j<=m; j++) {
            dp[i][j][0]=dp[i-1][j][0];
            dp[i][j][1]=dp[i-1][j][1];
            if (a[i]>b[j] && dp[i-1][j][1]>mlen1) mlen1=dp[i-1][j][1];
            if (a[i]<b[j] && dp[i-1][j][0]>mlen0) mlen0=dp[i-1][j][0];
            if (a[i]==b[j]) {
                dp[i][j][0]=mlen1+1;
                dp[i][j][1]=mlen0+1;
                ans=max(ans, mlen0+1);
                ans=max(ans, mlen1+1);
            }
        }
    }
    cout << ans ;
    return 0;
}