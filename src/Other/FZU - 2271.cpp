//#include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int dis[110][110];
int len[110][110];
bool mark[110][110];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    int T = 1;
    while (t--) {
        memset(dis, 0x3f, sizeof(dis));
        memset(len, 0, sizeof(len));
        memset(mark, 0, sizeof(mark));
        int n, m, ans = 0; scanf("%d%d", &n, &m);
        for (int i = 0, a, b, c; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            if (len[a][b]) {
                ans++;
                c = min(len[a][b], c);
            }
            len[a][b]=len[b][a]=dis[a][b]=dis[b][a]=c;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                // if (i == k) continue;
                for (int j = 1; j <= n; j++) {
                    // if (i == j || k == j) continue;
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // if ((len[i][j] && len[i][j] != dis[i][j]) || mark[i][j]) ans++;
                if (dis[i][j] == inf) continue;
                for (int k = 1; k <= n; k++) {
                    if (i == k || j == k) continue;
                    if (dis[i][k] + dis[k][j] <= len[i][j]) {
                        ans++; break;
                    }
                }
            }
        }
        printf("Case %d: %d\n", T++, ans);
    }
    return 0;
}