#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(2)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
int n, m; 
const int maxn=2e5+100;
int head[maxn], to[maxn<<1], nxt[maxn<<1], w[maxn<<1], Vcnt;
void add(int a, int b, int c) {
    to[++Vcnt] = b; w[Vcnt] = c; nxt[Vcnt] = head[a]; head[a] = Vcnt;
}
bool want[maxn];

struct pnode {
    int f, t;
    int w;
    bool operator < (const pnode& a) const {
        return w > a.w;
    }
};
int ans;
int dis[maxn];
bool vis[maxn];
void dijk() {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pnode> q;
    for (int i = 1; i <= n; i++) {
        if (want[i]) q.push(pnode{i, i, 0}), dis[i]=0;
    }
    pnode x;
    while (!q.empty()) {
        x = q.top(); q.pop();
        if (vis[x.t]) continue; vis[x.t] = 1;
        for (int i = head[x.t]; i; i = nxt[i]) {
            int t = to[i], c = w[i];
            if (want[t] && t != x.f) {
                ans = min(ans, x.w + c);
            }
            if (!vis[t] && dis[t] > dis[x.t] + c) {
                dis[t] = dis[x.t] + c;
                q.push(pnode{x.t, t, dis[t]});
            }
        }
    }
}
void init() {
    memset(want, 0, sizeof(want));
    memset(head, 0, sizeof(head));
    Vcnt = 0;
    ans = inf;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 0, a, b, c; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        int k; scanf("%d", &k);
        for (int i = 0, a; i < k; i++) {
            scanf("%d", &a); want[a] = 1;
        }
        dijk();
        printf("Case #%d: %d\n", TT, ans);
    }    
    return 0;
}