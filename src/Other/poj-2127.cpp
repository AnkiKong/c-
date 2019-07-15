#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=600;
ll a[maxn], b[maxn];
int dp[maxn][maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%lld", a+i);
    scanf("%d", &m);
    for (int i=1; i<=m; i++) scanf("%lld", b+i);
    int ans=0;
    for (int i=1; i<=n; i++) {
        int mlen=0;
        for (int j=1; j<=m; j++) {
            dp[i][j]=dp[i-1][j];
            if (b[j]<a[i] && dp[i-1][j]>mlen) mlen=dp[i-1][j];
            if (a[i]==b[j]) dp[i][j]=mlen+1, ans=max(ans, mlen+1);
        }
    }
    printf("%d\n", ans);
    return 0;
}