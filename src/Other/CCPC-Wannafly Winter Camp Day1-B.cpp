#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3fLL;

int dp[12][12];
int db[12][12];
int da[12][12];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, c;
    while (~scanf("%d%d%d", &n, &m, &c)) {
        memset(dp, -1, sizeof(dp));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                scanf("%d", da[i]+j);
            }
        }
        int sx, sy, tx, ty;
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        dp[sx][sy]=0;
        int ans=1;
        for (int nx, ny; ; ans++) {
            memcpy(db, dp, sizeof(dp));
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    for (int k=0; k<4; k++) {
                        nx=i+dx[k]; ny=j+dy[k];
                        if (nx>0 && nx<=n && ny>0 && ny<=m) {
                            dp[i][j]=max(dp[i][j], db[nx][ny]);
                        }
                    }
                    if (ans%da[i][j]==0 && dp[i][j]>=0) dp[i][j]++;
                }
            }
            if (dp[tx][ty]>=c) break;
        }
        cout << ans << "\n";
    }
    return 0;
}