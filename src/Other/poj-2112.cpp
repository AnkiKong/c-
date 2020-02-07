// #include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn=250;
int dis[maxn][maxn];
struct node {
    int f, to, nxt;
};
node ve[maxn * maxn];
int cnt;
int head[maxn];
void add(int u, int v, int f) {
    ve[cnt] = (node) {f, v, head[u]};
    head[u] = cnt++;
    ve[cnt] = (node) {0, u, head[v]};
    head[v] = cnt++;
}
int start, stop;
int vis[maxn];
int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[start] = 1; q.push(start);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (vis[stop]) return vis[stop];
        for (int i = head[now]; ~i; i = ve[i].nxt) {
            if (vis[ve[i].to] || !ve[i].f) continue;
            vis[ve[i].to] = vis[now] + 1;
            q.push(ve[i].to);
        }
    }
    return vis[stop];
}
int cur[maxn];
int dfs(int u, int f) {
    if (u == stop || !f) return f;
    int flow, sum = 0;
    for (int &i = cur[u]; ~i; i = ve[i].nxt) {
        int to = ve[i].to;
        if (vis[to] == vis[u] + 1 && (flow = dfs(to, min(f, ve[i].f)))) {
            sum += flow; f -= flow;
            ve[i].f -= flow; ve[i ^ 1].f += flow;
            if (!f) break;
        }
    }
    return sum;
}
int dinic() {
    int ans = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof(head));
        ans += dfs(start, inf);
    }
    return ans;
}
int k, c, m, total;
void build(int len) {
    memset(head, -1, sizeof(head));
    start = 0; stop = k + c + 1; cnt = 0;
    for (int i = 1; i <= k; i++) add(start, i, m);
    for (int i = 0; i < k; i++) {
        for (int j = k ; j < k + c; j++) {
            if (dis[i][j] <= len) add(i + 1, j + 1, 1);
        }
    }
    for (int i = k; i < k + c; i++) add(i, stop, 1);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d%d", &k, &c, &m)) {
        total = k + c;
        for (int i = 0; i < total; i++) {
            for (int j = 0; j < total; j++) {
                scanf("%d", dis[i] + j);
                if (!dis[i][j]) dis[i][j] = inf;
            }
        }
        for (int k = 0; k < total; k++) {
            for (int i = 0; i < total; i++) {
                for (int j = 0; j < total; j++) {
                    dis[i][j] =  min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int l = 1, r = inf;
        while (l < r) {
            int mid = (l + r) >> 1;
            build(mid);
            if (dinic() == c) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", r);
    }
    return 0;
}