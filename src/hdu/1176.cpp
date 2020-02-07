#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5 + 10;
char buf[100000],*p1=buf,*p2=buf;
inline char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x){
    char c=nc();x=0;
    if(c==EOF) return false;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    return true;
}
int dp[maxn][11];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while(rea(n), n) {
        memset(dp, 0, sizeof(dp));
        int a, b;
        int maxb = 0;
        for (int i = 0; i < n; i++) {
            rea(a); rea(b);
            maxb = max(maxb, b);
            dp[b][a]++;
        }
        for (int i = maxb - 1; i >= 0; i--) {
            dp[i][0] += max(dp[i+1][0], dp[i+1][1]);
            for (int j = 1; j < 10; j++) {
                dp[i][j] += max(dp[i+1][j-1], max(dp[i+1][j], dp[i+1][j+1]));
            }
            dp[i][10] += max(dp[i+1][10], dp[i+1][9]);
        }
        // int ans = 0;
        // for (int i = 0; i <= 10; i++) {
        //     ans = max(ans, dp[maxb][i]);
        // }
        printf("%d\n", dp[0][5]);
    }
    return 0;
}