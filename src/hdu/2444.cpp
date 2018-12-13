#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=400;
struct node {
    int to, nxt;
};
node ve[maxn*maxn];
bool vis[maxn];
int match[maxn];
int head[maxn];
int cnt;
void add(int u, int v) {
    ve[cnt] = (node) {v, head[u]};
    head[u] = cnt++;
    ve[cnt] = (node) {u, head[v]};
    head[v] = cnt++;
}
int dfs(int u) {
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        int to = ve[i].to;
        if (vis[to]) continue;
        vis[to] = 1;
        if (!match[to] || dfs(match[to])) {
            match[to] = u;
            return 1;
        }
    }
    return 0;
}
int cl[maxn];
int color(int u) {
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        int to = ve[i].to;
        if (!cl[to]) {
            cl[to] = !cl[u];
            if (!color(to)) return 0;
        } else if (cl[to] == cl[u]) {
            return 0;
        }
    }
    return 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0) {printf("No\n"); continue;}
        memset(head, -1, sizeof(head)); 
        int a, b; cnt = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            add(a, b);
        }
        memset(cl, 0, sizeof(cl));
        memset(match, 0, sizeof(match));
        if (color(1)) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                memset(vis, 0, sizeof(vis));
                ans += dfs(i);
            }
            printf("%d\n", ans>>1);
        } else {
            printf("No\n");
        }
    }
    return 0;
}