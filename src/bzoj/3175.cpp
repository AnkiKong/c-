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
const int maxn=8000;
int head[maxn], nxt[int(1e6)], to[int(1e6)], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
int vis[maxn], fa[maxn], id[210][210];
char str[210][210];
int tis;
int dfs(int u) {
    for (int i = head[u], t; i; i = nxt[i]) {
        t = to[i];
        if (vis[t] == tis) continue;
        vis[t] = tis;
        if (!fa[t] || dfs(fa[t])) {
            fa[t] = u; return 1;
        }
    }
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, idd = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < n; j++) {
            id[i][j] = ++idd;
        }
    }
    int dx[] = {1, 1, 2, 2};
    int dy[] = {2, -2, 1, -1};
    int xxx = 0;
    for (int i = 0, nx, ny; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i][j] == '1') {xxx++; continue;}
            for (int k = 0; k < 4; k++) {
                nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && str[nx][ny] == '0') {
                    add(id[i][j], id[nx][ny]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ++tis;
            ans += dfs(id[i][j]);
        }
    }
    printf("%d", n * n - xxx - ans);
    return 0;
}