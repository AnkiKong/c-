#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int mod=998244353;
// const int maxn=;
int dp[101][101][101][2];
inline void Madd(int& a, int b) {
    a += b;
    if (a>=mod) a-=mod;
    // return a;
}
void init(int n, int lc) {
    for (int i=0; i<=n; i++)
        for (int j=i; j<=n; j++)
            for (int k=j; k<=n; k++)
                dp[i][j][k][lc]=0;
}
#define pii pair<int,int>
vector<pii> v[102];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
// j,k,m,p代表 0,1,2,3 最后出现的下标
    int t; scanf("%d", &t);
    for (int n, m; t--; ) {
        for (int i=0; i<=n; i++) v[i].clear();
        scanf("%d%d", &n, &m);
        for (int i=0, a, b, c; i<m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            v[b].push_back(pii(a, c));
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0]=1;
        for (int i=1, p=1; i<=n; i++, p^=1) {
            init(i, p);
            for (int j=0; j<=i; j++)
                for (int k=j; k<=i; k++)
                    for (int m=k; m<=i; m++) {
                        Madd(dp[j][k][m][p], dp[j][k][m][p^1]);
                        Madd(dp[j][k][i-1][p], dp[j][k][m][p^1]);
                        Madd(dp[j][m][i-1][p], dp[j][k][m][p^1]);
                        Madd(dp[k][m][i-1][p], dp[j][k][m][p^1]);
                    }
            for (int j=0; j<=i; j++)
                for (int k=j; k<=i; k++)
                    for (int m=k; m<=i; m++)
                        for (pii a:v[i]) 
                            if ((i>=a.first) + (j>=a.first) + (k>=a.first) + (m>=a.first) != a.second)
                                dp[j][k][m][p]=0;
        }
        int ans=0;
        for (int j=0; j<=n; j++)
            for (int k=j; k<=n; k++)
                for (int m=k; m<=n; m++)
                    Madd(ans, dp[j][k][m][n&1]);
        printf("%d\n", ans);
    }
    return 0;
}