#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=600;
char a[maxn], b[maxn];
int dp[3][maxn][maxn];
const int mod = 1024523;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, l; 
    scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                int &val = dp[i&1][j][k], l = i + j - k;
                if (!val || l < 0 || l > m) continue;
                
                if (a[i + 1] == a[k + 1]) dp[(i+1)&1][j][k+1] = (dp[(i+1)&1][j][k+1] + val) % mod;
                if (a[i + 1] == b[l + 1]) dp[(i+1)&1][j][k] = (dp[(i+1)&1][j][k] + val) % mod;
                if (b[j + 1] == a[k + 1]) dp[i&1][j+1][k+1] = (dp[i&1][j+1][k+1] + val) % mod;
                if (b[l + 1] == b[j + 1]) dp[i&1][j+1][k] = (dp[i&1][j+1][k] + val) % mod;
                val = 0;
            }
        }
    }
    printf("%d\n", dp[(n+1)&1][m][n] % mod);
    return 0;
}