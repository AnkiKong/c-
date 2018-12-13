// #include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=2000;
const int inf = 0x3f3f3f3f;
vector<int> mp[maxn];
char str[100000];
int head[maxn];
struct node {
    int f, to, nxt, from;
};
node ve[maxn * maxn];
int n, m;
int cnt, stop, start;
void add (int u, int v, int w) {
    ve[cnt] = (node) {w, v, head[u], u};
    head[u] = cnt++;
    ve[cnt] = (node) {0, u, head[v], v};
    head[v] = cnt++;
}
int vis[maxn];
int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> q; q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        // if (vis[stop]) return vis[stop];
        for (int i = head[now]; ~i; i = ve[i].nxt) {
            if (!ve[i].f) continue;
            int to = ve[i].to;
            if (vis[to]) continue;
            vis[to] = vis[now] + 1;
            q.push(to);
        }
    }
    return vis[stop];
}
int cur[maxn];
int dfs(int u, int flow) {
    if (u == stop || flow == 0) return flow;
    int f, fl = 0;
    for (int& i = cur[u]; ~i; i = ve[i].nxt) {
        int to = ve[i].to;
        if (vis[to] == vis[u] + 1 && (f = dfs(to, min(flow, ve[i].f)))) {
            ve[i].f -= f; ve[i ^ 1].f += f;
            fl += f; flow -= f;
            if (!flow) break;
        }
    }
    return fl;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof(head));
        ans += dfs(start, inf);
    }
    return ans;
}
void build (int fl) {
    memset(head, -1, sizeof(head));
    cnt = 0;
    start = 0; stop = m + n + 1;
    for (int i = 1; i <= n; i++) add(start, i, 1);
    for (int i = 1; i <= n; i++) {
        // for (int to : mp[i]) 
        for (int j = 0; j < mp[i].size(); j++)
            add(i, mp[i][j], 1);
    }
    for (int i = 1; i <= m; i++) add(i + n, stop, fl);
}
int solve() {
    int l = 0, r = n;
    while (l < r) {
        int mid = (r + l) >> 1;
        build(mid);
        if (dinic() == n) r = mid;
        else l = mid + 1;
    }
    return r;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d%d", &n, &m), !(!n & !m)) {
        for (int i = 1; i <= n; i++) {
            mp[i].clear();
            getchar();
            scanf("%[^\n]+", str);
            int now = -1;
            for (int j = 0; 1; j++) {
                if (str[j] >= '0' && str[j] <= '9') {
                    if (now == -1) now = str[j] - '0';
                    else now = now * 10 + str[j] - '0';
                } else {
                    if (~now) mp[i].push_back(now + 1 + n);
                    now = -1;
                }
                if (!str[j]) break; 
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}