#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=210 * 210;
int head[maxn], to[int(2e5)], nxt[int(2e5)], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
int fa[maxn];
bool vis[maxn];
int dfs(int u) {
    for (int i = head[u], v; i; i = nxt[i]) {
        v = to[i];
        if (vis[v]) continue;
        vis[v] = 1;
        if (!fa[v] || dfs(fa[v])) {
            fa[v] = u; return 1;
        }
    }
    return 0;
}
int n;
char str[210][210];
inline int id(int x, int y) {
    return x * n + y;
}
bool check(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < n && str[x][y] == '0') return 1;
    return 0;
    // if (x < 0 || y < 0 || x > n || y > n || str[x][y] == '1') return 0;
    // return 1;
}
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i][j] == '1') continue;
            if ((i+j)&1) continue;
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!((nx+ny)&1)) continue;
                if (!check(nx, ny)) continue;
                add(id(i, j), id(nx, ny));
            }
        }
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i][j] == '1') continue;
            sum++;
            if ((i+j)&1) continue;
            memset(vis, 0, sizeof(vis));
            if (dfs(id(i, j))) ans++;
        }
    }
    printf("%d", sum - ans);
    return 0;
}