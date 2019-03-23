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
const int maxn=4000;
const int maxm=7e4+100;
int n, m;
int head[maxn], to[maxm<<1], w[maxm<<1], nxt[maxm<<1], vcnt;
void add(int a, int b, int c) {
    to[++vcnt] = b; w[vcnt] = c; nxt[vcnt] = head[a]; head[a] = vcnt;
}
vector<int> loc[maxn];
int scnt[maxn];
struct node {
    int t, w;
    bool operator < (const node& a) const {
        return w > a.w;
    }
};
int dis[maxn];
bool vis[maxn];
void dijk() {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    q.push(node{1, 0}); dis[1] = 0;
    while (!q.empty()) {
        node x = q.top(); q.pop();
        if (vis[x.t]) continue;
        vis[x.t] = 1;
        // for (int a : loc[x.t]) {
        for (int i = 0; i < loc[x.t].size(); i++) {
            int a = loc[x.t][i];
            scnt[a]--;
            if (!scnt[a] && dis[a] != inf) 
                q.push(node{a, max(dis[a], x.w)});
            dis[a] = max(dis[a], x.w);
        }
        for (int i = head[x.t]; i; i = nxt[i]) {
            int t = to[i];
            if (!vis[t] && dis[t] > dis[x.t] + w[i]) {
                dis[t] = dis[x.t] + w[i];
                if (!scnt[t]) q.push(node{t, dis[t]});
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
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", scnt+i);
        for (int j = 0; j < scnt[i]; j++) {
            scanf("%d", &a);
            loc[a].push_back(i);
        }
    }
    dijk();
    printf("%d", dis[n]);
    return 0;
}