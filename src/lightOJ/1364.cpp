#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const double eps = 1e-8;
// const int maxn=;
double dp[16][16][16][16][5][5];
void init() {
    for (int _1 = 0; _1 < 14; _1++) 
        for (int _2 = 0; _2 < 14; _2++) 
            for (int _3 = 0; _3 < 14; _3++) 
                for (int _4 = 0; _4 < 14; _4++) 
                    for (int _5 = 0; _5 < 5; _5++) 
                        for (int _6 = 0; _6 < 5; _6++) 
                            dp[_1][_2][_3][_4][_5][_6] = -1;
}
int A, B, C, D;
int cnt[6];
int check(int a, int b, int c, int d, int e, int f) {
    cnt[1] = a, cnt[2] = b, cnt[3] = c, cnt[4] = d;
    if (e) cnt[e]++;
    if (f) cnt[f]++;
    if (cnt[1] < A || cnt[2] < B || cnt[3] < C || cnt[4] < D) return 0;
    return 1;
}

double dfs(int a, int b, int c, int d, int e, int f) {
    if (check(a, b, c, d, e, f)) return dp[a][b][c][d][e][f] = 0;
    if (dp[a][b][c][d][e][f] > eps) return dp[a][b][c][d][e][f];
    int sum = a + b + c + d + (e != 0) + (f != 0);
    double ans = 0;
    if (sum == 54) return dp[a][b][c][d][e][f] = 0;
    if (a < 13) ans += dfs(a + 1, b, c, d, e, f) * (13 - a);
    if (b < 13) ans += dfs(a, b + 1, c, d, e, f) * (13 - b);
    if (c < 13) ans += dfs(a, b, c + 1, d, e, f) * (13 - c);
    if (d < 13) ans += dfs(a, b, c, d + 1, e, f) * (13 - d);
    if (!e) {
        double tmp = 100;
        for (int i = 1; i <= 4; i++) {
            tmp = min(tmp, dfs(a, b, c, d, i, f));
        }
        ans += tmp;
    }
    if (!f) {
        double tmp = 100;
        for (int i = 1; i <= 4; i++) {
            tmp = min(tmp, dfs(a, b, c, d, e, i));
        }
        ans += tmp;
    }
    return dp[a][b][c][d][e][f] = ans / (54 - sum) + 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d%d%d", &A, &B, &C, &D);
        if (max(0, A - 13) + max(0, B - 13) + max(0, C - 13) + max(0, D - 13) > 2) {
            printf("Case %d: -1\n", TT);
        } else {
            init();
            printf("Case %d: %.10f\n", TT, dfs(0, 0, 0, 0, 0, 0));
        }
    }
    return 0;
}