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
const int maxn=2e6+100;
int n, m;
int start, stop;
int head[maxn], to[maxn<<2], nxt[maxn<<2], w[maxn<<2], vcnt;
void _add(int a, int b, int c) {
    to[++vcnt] = b; w[vcnt] = c; nxt[vcnt] = head[a]; head[a] = vcnt;
}
void add(int a, int b, int c) {
    _add(a, b, c);
    _add(b, a, c);
}

bool vis[maxn];
int dis[maxn];
struct node {
    int t, dis;
    bool operator < (const node& a) const {
        return dis > a.dis;
    }
};
void dijk() {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    q.push(node{0, 0}); dis[0] = 0;
    while(!q.empty()){
        node x = q.top(); q.pop();
        // printf("%d---\n", x.dis);
        if (vis[x.t]) continue;
        vis[x.t] = 1;
        for (int i = head[x.t]; i; i = nxt[i]) {
            int t = to[i];
            if (!vis[t] && dis[t] > dis[x.t] + w[i]) {
                dis[t] = dis[x.t] + w[i];
                q.push(node{t, dis[t]});
            }
        }
    }
    
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    if (n == 1 || m == 1) {
        if (n < m) swap(n, m);
        int ans = inf;
        for (int i = 1, a; i < n; i++) {
            scanf("%d", &a); ans = min(ans, a);
        }
        printf("%d", ans);
        return 0;
    }
    start = 0, stop = n * m * 2 + 1;
    for (int i = 1, a; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &a);
            if (i == 1) add(j*2 + (i-1) * (m-1) * 2, stop, a);
            else if (i!=n) add(j*2 + (i-1) * (m-1) * 2, j*2 + (i-2) * (m-1) * 2 - 1, a);
            else add(start, j*2 + (i-2) * (m-1) * 2 - 1, a);
        }
    }
    for (int i = 1, a; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            if (j == 1) add(j*2 + (i-1) * (m-1) * 2 - 1, start, a);
            else if (j != m) add(j*2 + (i-1) * (m-1) * 2 - 1, j*2 + (i-1) * (m-1) * 2 - 2, a);
            else add(j*2 + (i-1) * (m-1) * 2 - 2, stop, a);
        }
    }
    for (int i = 1, a; i < n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &a);
            add(j*2 + (i-1) * (m-1) * 2, j*2 + (i-1) * (m-1) * 2 - 1, a);
        }
    }
    dijk();
    printf("%d\n", dis[stop]);
    return 0;
}