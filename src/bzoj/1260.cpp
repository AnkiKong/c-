#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
char str[100];
int dp[100][100];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str+1);
    int n = strlen(str+1), j;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            j = i + l - 1;
            dp[i][j] = dp[i][j-1] + (str[j] != str[i]);
            for (int k = i; k < j; k++) {
                if (str[k] == str[j]) 
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j-1]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}