#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=5e4+100;
const int maxm=2e7;
const int mod=1e9+7;
int head[maxn], nxt[maxm], to[maxm], vcnt;
bool vis[maxn];
void add(int a, int b) {
    to[++vcnt]=b; nxt[vcnt]=head[a]; head[a]=vcnt;
}
#define pii pair<int,int>
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int cnt, st;
        vcnt=0;
        memset(head, 0, sizeof(head));
        for (int i=0; i<m; i++) {
            scanf("%d%d", &cnt, &st);
            for (int i=1, t; i<cnt; i++) {
                scanf("%d", &t);
                add(st, t); add(t, st);
                st=t;
            }
        }    
        queue<pii > q; q.push(pii(1, 1));
        memset(vis, 0, sizeof(vis));
        pii x;
        int mx=0, loc;
        while (!q.empty()) {
            x=q.front(); q.pop();
            if (x.second>mx) loc=x.first, mx=x.second;
            for (int i=head[x.first]; i; i=nxt[i]) {
                if (!vis[to[i]]) {
                    vis[to[i]]=1; q.push(pii(to[i], x.second+1));
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        mx=0; q.push(pii(loc, 0));
        while (!q.empty()) {
            x=q.front(); q.pop();
            if (x.second>mx) mx=x.second;
            for (int i=head[x.first]; i; i=nxt[i]) {
                if (!vis[to[i]]) {
                    vis[to[i]]=1; q.push(pii(to[i], x.second+1));
                }
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}