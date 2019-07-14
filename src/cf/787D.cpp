#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3fLL;
const int maxn=1e5+100;
const int M=4e6+100;
int head[M], to[M], nxt[M], w[M], Tcnt;
void add(int a, int b, int c) {
    to[++Tcnt]=b; nxt[Tcnt]=head[a]; w[Tcnt]=c; head[a]=Tcnt;
}
int id[M], pos;
void build(int l, int r, int rt) {
    if (l==r) {
        id[l]=rt;
        add(rt+pos, (rt>>1)+pos, 0);
        add(rt, rt+pos, 0);
    } else {
        build(l, mid, ls);
        build(mid+1, r, rs);
        add(rt, ls, 0);
        add(rt, rs, 0);
        add(rt+pos, (rt>>1)+pos, 0);
    }
}
queue<int> wait;
void query(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) {
        wait.push(rt);
    } else {
        if (L<=mid) query(l, mid, L, R, ls);
        if (mid<R) query(mid+1, r, L, R, rs);   
    }
}
ll dis[M];
bool vis[M];
void dijk(int s) {
#define pii pair<ll,int>
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pii> q;
    q.push(pii(0LL, id[s])); dis[id[s]]=0;
    while (!q.empty()) {
        int x=q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x]=1;
        for (int i=head[x], t; i; i=nxt[i]) {
            if (vis[t=to[i]]) continue;
            if (dis[x]+w[i]<dis[t]) {
                dis[t]=dis[x]+w[i];
                q.push(pii(-dis[t], t));
            }
        }
    }
#undef pii
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, q, s;
    scanf("%d%d%d", &n, &q, &s);
    pos=n<<2;
    build(1, n, 1);
    for (int i=0, a, b, c, d, o; i<q; i++) {
        scanf("%d", &o);
        if (o==1) {
            scanf("%d%d%d", &a, &b, &c);
            add(id[a], id[b], c);
        } else if (o==2) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            query(1, n, b, c, 1);
            for (int t; !wait.empty(); wait.pop()) {
                t=wait.front();
                add(id[a], t, d);
            }
        } else {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            query(1, n, b, c, 1);
            for (int t; !wait.empty(); wait.pop()) {
                t=wait.front();
                add(t+pos, id[a], d);
            }
        }
    }
    dijk(s);
    for (int i=1; i<=n; i++) {
        if (dis[id[i]]==linf) printf("-1 ");
        else printf("%lld ", dis[id[i]]);
    }
    return 0;
}