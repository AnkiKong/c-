#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5 + 100;
struct node {
    int u, w, nxt;
}v[maxn << 2];
struct node2 {
    int pos;
    ll dis;
    bool operator < (const node2& tmp) const {
        return dis > tmp.dis;
    }
}da[maxn][4];
int n, m, cnt = 1;
int head[maxn];
void add(int a, int b, int c) {
    v[cnt] = (node) {b, c, head[a]}; head[a] = cnt++;
}
ll ans;
void dfs1(int u, int fa) {
    for (int i = head[u]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (to == fa) continue;
        dfs1(to, u);
        da[u][3].dis = da[to][0].dis + v[i].w, da[u][3].pos = to;
        sort(da[u], da[u] + 4);
    }
    ans = max(ans, da[u][0].dis + da[u][1].dis * 2 + da[u][2].dis);
}
bool vis[maxn];
void dfs2(int u) {
    vis[u] = 1;
    for (int i = head[u]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (!vis[to]) continue;
        if (u != da[to][0].pos) da[u][3].dis = da[to][0].dis + v[i].w;
        else da[u][3].dis = da[to][1].dis + v[i].w;
        da[u][3].pos = to;
        sort(da[u], da[u] + 4);
        break;
    }
    ans = max(ans, da[u][0].dis + da[u][1].dis * 2 + da[u][2].dis);
    for (int i = head[u]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (!vis[to]) dfs2(to);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    dfs1(1, -1);
    dfs2(1);
    printf("%lld\n", ans);
    return 0;
}