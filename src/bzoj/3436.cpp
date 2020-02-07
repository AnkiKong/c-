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
const int maxn=1e5 + 100;
int head[maxn], to[maxn<<1], nxt[maxn<<1], w[maxn<<1], vcnt;
void add(int a, int b, int v) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; w[vcnt] = v; head[a] = vcnt;
}
ll dis[maxn];
bool inq[maxn];
int cir[maxn], n;
int spfa() {
    queue<int> q;
    memset(dis, 0x3f3f, sizeof(dis));
    inq[0] = 1; q.push(0); dis[0] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop(); inq[x] = 0;
        for (int i = head[x]; i; i = nxt[i]) {
            if (dis[x] + w[i] < dis[to[i]]) {
                if ((cir[to[i]] = cir[x] + 1) > n) return 0;
                dis[to[i]] = dis[x] + w[i];
                if (!inq[to[i]]) inq[to[i]] = 1, q.push(to[i]);
            }
        }
    }
    return 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int m; scanf("%d%d", &n, &m);
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            if (a == b && c) {printf("NO\n"); return 0;}
            add(a, b, -c);
        } else if (a == 2) {
            scanf("%d%d%d", &a, &b, &c);
            if (a == b && c) {printf("NO\n"); return 0;}
            add(b, a, c);
        } else {
            scanf("%d%d", &a, &b);
            add(a, b, 0); add(b, a, 0);
        }
    }
    for (int i = 1; i <= n; i++) add(0, i, 0);
    if (spfa()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    // for (int i = 1; i <= n; i++) printf(lld " ", dis[i]);
    return 0;
}