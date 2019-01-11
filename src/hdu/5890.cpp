#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
int da[60];
bool vis[60][60][60];
bitset<90> bs[11];
int n;
int check(int a, int b, int c) {
    for (int i = 0; i < 11; i++) bs[i].reset();
    bs[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b || i == c || da[i] > 87) continue;
        for (int j = 10; j > 0; j--) {
            bs[j] |= bs[j-1]<<da[i];
        }
        if (bs[10][87]) return 1;
    }
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) scanf("%d", da+i);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    vis[i][j][k] = vis[i][k][j] = vis[j][i][k] = vis[j][k][i] = vis[k][i][j] = vis[k][j][i] = check(i, j, k);
                }
            }
        }
        int q; scanf("%d", &q);
        while (q--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            printf("%s\n", vis[a][b][c] ? "Yes" : "No");
        }
    }
    return 0;
}