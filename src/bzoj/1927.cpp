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
const int maxn=2000;
const int maxm=3000100;
int start, stop;
int head[maxn], nxt[maxm], to[maxm], f[maxm], w[maxm], fr[maxm], vcnt;
void _add(int a, int b, int c, int ww) {
    to[vcnt]=b; f[vcnt]=c; w[vcnt]=ww; nxt[vcnt]=head[a]; fr[vcnt] = a; head[a]=vcnt++;
}
void add(int a, int b, int c, int ww) {
    _add(a, b, c, ww);
    _add(b, a, 0, -ww);
}
int dis[maxn], from[maxn];
bool inq[maxn];
bool spfa() {
    memset(dis, 0x3f, sizeof(dis));
    memset(inq, 0, sizeof(inq));
    deque<int> q;
    q.push_back(0); dis[0]=0; inq[0]=1;
    while(!q.empty()){
        int x = q.front(); q.pop_front(); inq[x] = 0;
        for (int i=head[x]; ~i; i=nxt[i]) {
            if (f[i] && dis[to[i]] > dis[x]+w[i]) {
                dis[to[i]] = dis[x] + w[i];
                from[to[i]] = i;
                if (!inq[to[i]]) {
                    inq[to[i]] = 1;
                    if (q.size() && dis[to[i]] < dis[q.front()]) {
                        q.push_front(to[i]); 
                    } else {
                        q.push_back(to[i]);
                    }
                }
            }
        }
    }
    return dis[stop] != inf;
}
int ans;
void mcf() {
    int x = inf;
    for (int i = stop; i; i=fr[from[i]]) {
        x = min(x, f[from[i]]);
    }
    for (int i = stop; i; i=fr[from[i]]) {
        ans += x * w[from[i]];
        f[from[i]] -= x; f[from[i]^1] += x;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(head, -1, sizeof(head));
    int n, m; scanf("%d%d", &n, &m);
    start = 0; stop = 2 * n + 1;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        add(start, i, 1, 0);
        add(start, i+n, 1, a);
        add(i+n, stop, 1, 0);
    }
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a > b) swap(a, b);
        add(a, b+n, 1, c); 
    }
    while(spfa()){
        mcf();
    }
    printf("%d\n", ans);
    
    return 0;
}