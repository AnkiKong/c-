#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
int da[510][510];
int vis[510][510];
int r, c;
int ans=-0x3f3f3f3f;
int cnt;
int dfs(int x, int y) {
    int& res = vis[x][y];
    if (res != -1) return res;
    if (x > r || y > c) return res=-inf;
    if (x == r && y == c) return res = 0;
    res = da[x][y];
    dfs(x+1, y); dfs(x, y+1);
    res = min(res, da[x][y] + max(vis[x+1][y], vis[x][y+1]));
    return res;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &r, &c);
        memset(vis, -1, sizeof(vis));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                scanf("%d", da[i]+j);
            }
        }
        cnt = 0;
        dfs(1, 1);
        ans = vis[1][1];
        printf("%d\n", 1 + max(0, -ans));

    }
    return 0;
}