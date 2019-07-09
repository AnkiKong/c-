#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int maxn=2e5+100;
int head[maxn], nxt[maxn<<3], to[maxn<<3], vcnt;
ll w[maxn<<3];
void _add(int a, int b, ll c) {
    to[++vcnt]=b; w[vcnt]=c; nxt[vcnt]=head[a]; head[a]=vcnt;
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
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, k, fi;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        vcnt=0;
        memset(head, 0, sizeof(head));
        memset(dis, 0x3f3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &fi); fi+=k;
        _add(1, 1+n, 0);
        for (int i=2, a; i<=n; i++) {
            scanf("%d", &a);
            if (a>fi)
                _add(i, i+n, 1LL*(a-fi)*(a-fi));
            else
                _add(i, i+n, 0);
        }
        for (int i=0, a, b, c; i<m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            _add(a+n, b, c);
            _add(b+n, a, c);
            // add(a+n, b, c);
        }
        priority_queue<node> q;
        q.push(node{1, 0LL}); dis[1]=0;
        while (!q.empty()) {
            node tmp=q.top();q.pop();
            if (vis[tmp.x]) continue;
            vis[tmp.x]=1;
            for (int i=head[tmp.x], t; i; i=nxt[i]) {
                if (vis[t=to[i]]) continue;
                if (dis[t]>dis[tmp.x]+w[i]) {
                    dis[t]=dis[tmp.x]+w[i];
                    q.push(node{t, dis[t]});
                }
            }
        }
        printf("%lld\n", dis[n+n]);
    }
    return 0;
}