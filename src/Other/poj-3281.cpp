#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn=1e6;
const int inf = 0x3f3f3f3f;
struct node {
    int to, f, nxt, from;
    node (int a, int b, int c, int d) : to(a), f(b), nxt(c), from(d){}
    node() {}
};
node ve[maxn];
int head[1000];
int cnt;
void add(int u, int v, int f) {
    ve[cnt] = node(v, f, head[u], u);
    head[u] = cnt++;
    ve[cnt] = node(u, 0, head[v], v);
    head[v] = cnt++;
}
int vis[1000];
int pre[1000];
int stop;
int bfs() {
    queue<int> q;
    q.push(0);
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (vis[stop]) return vis[stop];
        for (int i = head[now]; ~i; i = ve[i].nxt) {
            if (!vis[ve[i].to] && ve[i].f) {
                vis[ve[i].to] = vis[now] + 1;
                q.push(ve[i].to);
            } 
        }
    }
    return vis[stop];
}
int cur[1000];
int dfs(int v, int flow) {
    int fl, sum = 0;
    if (v == stop || flow == 0) return flow;
    for (int &i = cur[v]; ~i; i = ve[i].nxt) {
        node &tmp = ve[i];
        if (vis[tmp.to] = vis[v] + 1 && (fl = dfs(tmp.to, min(flow, tmp.f))) != 0) {
            ve[i].f -= fl, ve[i ^ 1].f += fl;
            sum += fl; flow -= fl;
            if (!flow) break;
        }
    }
    return sum;
}
int ek() {
    int ans = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof(head));
        ans += dfs(0, inf);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, f, d;
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &f, &d);
    int c1, c2, a;
    for (int i = 1; i <= f; i++) {
        add(0, i, 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c1, &c2);
        for (int j = 1; j <= c1; j++) {
            scanf("%d", &a);
            add(a, i + 100, 1);
        }
        add(i + 100, i + 200, 1);
        for (int j = 1; j <= c2; j++) {
            scanf("%d", &a);
            add(i + 200, a + 300, 1);
        }
    }
    stop = 400;
    for (int i = 301; i <= 300 + d; i++) {
        add(i, stop, 1);
    }
    printf("%d", ek());
    return 0;
}