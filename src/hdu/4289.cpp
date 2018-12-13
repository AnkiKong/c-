#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=410;
const int inf = 0x3f3f3f3f;
struct node {
    int f, to, nxt;
};
node ve[maxn * maxn];
int head[maxn];
int cnt, n, m;
int vis[maxn];
void add(int u, int v, int f) {
    ve[cnt] = (node) {f, v, head[u]};
    head[u] = cnt++;
    ve[cnt] = (node) {0, u, head[v]};
    head[v] = cnt++;
}
int start, stop;
int dep[maxn], gap[maxn];
void bfs() {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1, dep[stop] = 0;
    queue<int> q; q.push(stop);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = head[now]; ~i; i = ve[i].nxt) {
            int to = ve[i].to;
            if (dep[to] != -1) continue;
            q.push(to); dep[to] = dep[now] + 1;
            gap[dep[to]]++;
            // if (~dep[stop]) printf("R\n");
        }
    }
}

int cur[maxn], s[maxn];
int sap() {
    bfs();
    memcpy(cur, head, sizeof(head));
    int u = start, ans = 0, top = 0;
    while (dep[start] < n) {
        if (u == stop) {
            int flow = inf, inser;
            for (int i = 0; i < top; i++) {
                if (flow > ve[s[i]].f) {
                    flow = ve[s[i]].f, inser = i;
                }
            }
            for (int i = 0; i < top; i++) {
                ve[s[i]].f -= flow;
                ve[s[i] ^ 1].f += flow;
            }
            ans += flow; top = inser, u = ve[s[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; ~i; i = ve[i].nxt) {
            v = ve[i].to;
            if (ve[i].f && dep[v] + 1 == dep[u]) {
                flag = true; cur[u] = i; break;
            }
        }
        if (flag) {
            s[top++] = cur[u]; u = v; continue;
        }
        int Min = n;
        for (int i = head[u]; ~i; i = ve[i].nxt) {
            if (ve[i].f && dep[ve[i].to] < Min) {
                Min = dep[ve[i].to]; cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if (!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start) u = ve[s[--top]^1].to;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int cost;
    while (~scanf("%d%d", &n, &m)) {
        memset(head, -1, sizeof(head)); cnt = 0;
        scanf("%d%d", &start, &stop);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &cost);
            add(i, i + n, cost);
            add(i + n, i, cost);
        }
        int a, b;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            add(a + n, b, inf);
            add(b + n, a, inf);
        }
        stop += n;
        n <<= 1;
        printf("%d\n", sap());
    }
    return 0;
}