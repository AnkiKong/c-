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
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, l; 
    scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (!dp[i&1][j][k]) continue;
                l = i + j - k;
                
            }
        }
    }
    return 0;
}