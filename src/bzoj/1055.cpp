#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
char str[4][20][4];
int dp[220][220][4];
char s[220];
int cnt[4];
void to(char& tt) {
    if (tt == 'W') tt = 0;
    else if (tt == 'I') tt = 1;
    else if (tt == 'N') tt = 2;
    else if (tt == 'G') tt = 3;
}
int dfs(int l, int r, int x) {
    if (l == r) return s[l] == x;
    if (~dp[l][r][x]) return dp[l][r][x];
    dp[l][r][x] = 0;
    for (int i = l; i < r; i++) {
        for (int j = 0; j < cnt[x]; j++) {
            if (dfs(l, i, str[x][j][0]) && dfs(i+1, r, str[x][j][1]))
                return dp[l][r][x] = 1;
        }
    }
    return dp[l][r][x] = 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 4; i++) {
        scanf("%d", cnt + i);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            scanf("%s", str[i][j]), to(str[i][j][0]), to(str[i][j][1]);
        }
    }
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; s[i]; i++) to(s[i]);
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        if (dfs(0, len - 1, i)) {
            putchar("WING"[i]), flag = 1;
        }
    }
    if (!flag) printf("The name is wrong!");
    return 0;
}