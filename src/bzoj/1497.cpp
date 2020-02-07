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
const int maxn=6e4;
int head[maxn], to[maxn<<6], nxt[maxn<<6], w[maxn<<6], vcnt;
void add(int a, int b, int c) {
    to[vcnt] = b; w[vcnt] = c; nxt[vcnt] = head[a]; head[a] = vcnt++;
}
int start, stop;
int dep[maxn];
bool bfs() {
    memset(dep, -1, sizeof(dep));
    queue<int> q; q.push(start);
    dep[start] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for (int i = head[x]; ~i; i = nxt[i]) {
            if (w[i] && dep[to[i]] == -1) {
                q.push(to[i]);
                dep[to[i]] = dep[x] + 1;
            }
        }
    }
    return dep[stop] != -1;
}
int dfs(int u, int flow) {
    if (u == stop) return flow;
    int res = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int t = to[i];
        if (w[i] && dep[t] == dep[u] + 1) {
            int f = dfs(t, min(flow, w[i]));
            flow -= f; w[i] -= f; w[i^1] += f;
            res += f;
            if (!flow) break;
        }
    }
    if (!res) dep[u] = -1;
    return res;
}
int dinic() {
    int ans = 0;
    while (bfs()) {
        ans += dfs(start, inf);
    }
    return ans;
}
void init() {
    memset(head, -1, sizeof(head));
    vcnt = 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        init();
        start = 0, stop = n + m + 1;
        for (int i = 1, a; i <= n; i++) {
            scanf("%d", &a);
            add(start, i, a);
            add(i, start, 0);
        }
        int sum = 0;
        for (int i = 1, a, b, c; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, i+n, inf); add(i+n, a, 0);
            add(b, i+n, inf); add(i+n, b, 0);
            add(i+n, stop, c); add(stop, i+n, 0);
            sum += c;
        }
        printf("%d\n", sum - dinic());
    }
    return 0;
}