#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=310;
struct node {
    int to, nxt;
};
node ve[maxn*maxn];
int head[maxn];
int cnt;
void add(int u, int v) {
    ve[cnt] = (node) {v, head[u]};
    head[u] = cnt++;
    // ve[cnt] = (node) {u, head[v]};
    // head[v] = cnt++;
}
bool vis[maxn];
int match[maxn];
int dfs(int u) {
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        int to = ve[i].to;
        if (vis[to]) continue;
        vis[to] = 1;
        if(!match[to] || dfs(match[to])) {
            match[to] = u;
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
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int p, n; scanf("%d%d", &p, &n);
        cnt = 0; memset(head, -1, sizeof(head));
        for (int i = 1; i <= p; i++) {
            int ccnt, a; scanf("%d", &ccnt);
            for (int j = 0; j < ccnt; j++) {
                scanf("%d", &a);
                add(i, a);
            }
        }
        int ans = 0;
        memset(match, 0, sizeof(match));
        for (int i = 1; i <= p; i++) {
            memset(vis, 0, sizeof(vis));
            ans += dfs(i);
        }
        if (ans == p) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}