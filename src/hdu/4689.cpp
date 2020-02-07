#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=30;
char str[maxn];
ll dp[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%s", str+1)) {
        int n=strlen(str+1);
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for (int i=1; i<=n; i++) {
            if (str[i]=='+') {
                for (int j=1; j<=i; j++)
                    dp[i][j]+=dp[i-1][j]*j+dp[i-1][j-1];
            } else {
                for (int j=1; j<=i; j++) {
                    dp[i][j-1]+=dp[i-1][j]*j*j;
                    dp[i][j]+=dp[i-1][j]*j;
                }
            }
        }
        printf("%lld\n", dp[n][0]);
    }
    return 0;
}