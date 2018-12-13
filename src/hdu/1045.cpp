#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=100;
vector<int> mp[200];
bool vis[200];
int match[200];
char rmp[10][10];
int nx[10][10], ny[10][10];
int cntx, cnty;
int dfs(int t) {
    for (auto a : mp[t]) {
        if (vis[a]) continue;
        vis[a] = 1;
        if (match[a] == 0 || dfs(match[a])) {
            match[a] = t;
            return 1;
        }
    }
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n) && n) {
        memset(match, 0, sizeof(match));
        for (int i = 0; i < n; i++) {
            scanf("%s", rmp[i]);
        }
        cntx = 1, cnty = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rmp[i][j] == '.') nx[i][j] = cntx;
                else cntx++;
            }
            cntx++;
            for (int j = 0; j < n; j++) {
                if (rmp[j][i] == '.') ny[j][i] = cnty;
                else cnty++;
            }
            cnty++;
        }
        for (int i = 0; i <= cntx; i++) mp[i].clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rmp[i][j] == '.') {
                    mp[nx[i][j]].push_back(ny[i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < cntx; i++) {
            memset(vis, 0, sizeof(vis));
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}