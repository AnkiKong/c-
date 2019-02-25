#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5e5 + 100;
int dp1[maxn][2], dp2[maxn][2];
char str[maxn];
int n;
void dfs(int a) {
    if (str[a] == '0') {
        dp1[a][0] = 0;
        dp1[a][1] = 1;
        dp2[a][0] = 0;
        dp2[a][1] = 1;
    } else if (str[a] == '1') {
        dfs(++n);
        dp1[a][1] = dp1[a+1][0] + 1;
        dp1[a][0] = max(dp1[a+1][1], dp1[a+1][1]);
        dp2[a][1] = dp2[a+1][0] + 1;
        dp2[a][0] = min(dp2[a+1][0], dp2[a+1][1]);
    } else {
        int y1 = n + 1;
        dfs(++n);
        int y2 = n + 1;
        dfs(++n);
        dp1[a][1] = dp1[y2][0] + dp1[y1][0] + 1;
        dp1[a][0] = max(dp1[y1][0] + dp1[y2][1], dp1[y1][1] + dp1[y2][0]);
        dp2[a][1] = dp2[y1][0] + dp2[y2][0] + 1;
        dp2[a][0] = min(dp2[y1][0] + dp2[y2][1], dp2[y1][1] + dp2[y2][0]);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    dfs(n);
    printf("%d %d\n", max(dp1[0][1], dp1[0][0]), min(dp2[0][1], dp2[0][0]));
    return 0;
}