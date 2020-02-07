#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+100;
const int maxm=1e6+100;
int head[maxn], to[maxm], nxt[maxm],  vcnt;
ll w[maxm];
void _add(int a, int b, ll c) {
    ++vcnt; to[vcnt]=b, nxt[vcnt]=head[a]; w[vcnt]=c; head[a]=vcnt;
}
void add(int a, int b, ll c) {
    _add(a, b, c);
    _add(b, a, c);
}
struct node {
    int x;
    ll dis;
    bool operator < (const node& a) const {
        return dis > a.dis;
    }
};
ll dis[maxn];
bool vis[maxn];
int n, k, X, m, s;
void dijk() {
    priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push(node{s, 0}); dis[s]=0;
    while (!q.empty()) {
        node x=q.top(); q.pop();
        if (vis[x.x]) continue;
        vis[x.x] = 1;
        for (int i=head[x.x]; i; i=nxt[i]) {
            if (!vis[to[i]] && dis[to[i]]>dis[x.x]+w[i]) {
                dis[to[i]]=dis[x.x]+w[i];
                q.push(node{to[i], dis[to[i]]});
            }
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    int t; scanf("%d", &t);
    while (t--) {
        vcnt=0; memset(head, 0, sizeof(head));
        scanf("%d%d%d%d%d", &n, &k, &X, &m, &s);
        for (int i = 0, a, b, c; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        for (int i = 1; i <= k; i++) {
            _add(i, 0, 0);
            _add(0, i, X);
        }
        dijk();
        for (int i = 1; i <= n; i++) {
            printf("%lld%c", dis[i], i==n?'\n':' ');
        }
    }
    return 0;
}