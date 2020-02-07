#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int maxn=2100;
int dp[maxn][maxn];
int n, m;
int dfs(int a, int b) {
    if (a-b>n || b-a>m) return 0;
    if (!a || !b) return 1;
    if (~dp[a][b]) return dp[a][b];
    dp[a][b]=dfs(a-1, b)+dfs(a, b-1);
    return dp[a][b]%=mod;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    for (; cin >> n >> m; ) {
        for (int i=0; i<=n+m; i++) {
            for (int j=0; j<=n+m; j++) {
                dp[i][j]=-1;
            }
        }
        cout << dfs(n+m, n+m) << "\n";
    }
    return 0;
}