#include <bits/stdc++.h>
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5+10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 78294349;
const double eps = 1e-8;
const int maxn=1e4+1000;
int n, k; 
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}

int son[maxn], sz[maxn], dep[maxn], fa[maxn];
int sum[maxn], id[maxn], top[maxn], idd;
void dfs1(int u, int f) {
    fa[u] = f; sz[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == f) continue;
        dep[to[i]] = dep[u] + 1; dfs1(to[i], u);
        sz[u] += sz[to[i]];
        if (sz[to[i]] > sz[son[u]]) son[u] = to[i];
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; id[u] = ++idd;
    if (son[u])
        dfs2(son[u], tp);
    for (int i = head[u]; i; i = nxt[i])
        if (to[i] != fa[u] && to[i] != son[u])
            dfs2(to[i], to[i]);
}
int mx[maxn<<2], tag[maxn<<2];
int cnt[maxn<<2];
bool same[maxn<<2];
void build(int l, int r, int rt) {
    mx[rt]=tag[rt]=0;
    same[rt]=1; cnt[rt]=0;
    if (l==r) return;
    build(l, mid, ls);
    build(mid+1, r, rs);
}
void clr(int l, int r, int rt) {
    if (mx[rt]==0) return;
    cnt[rt]=mx[rt]=tag[rt]=0; same[rt]=1;
    if (l==r) return;
    clr(l, mid, ls);
    clr(mid+1, r, rs);
}
void pushDown(int rt) {
    if (tag[rt]) {
        tag[ls]+=tag[rt]; tag[rs]+=tag[rt];
        mx[ls]+=tag[rt];  mx[rs]+=tag[rt];
        tag[rt]=0;
    }
}
void pushUp(int rt) {
    mx[rt]=max(mx[rs], mx[ls]);
    same[rt]=same[ls] && same[rs] && mx[rs]==mx[ls];
    cnt[rt]=cnt[ls]+cnt[rs];
}
void update(int l, int r, int L, int R, int rt, int val) {
    if (L<=l && r<=R) {
        tag[rt]+=val;
        mx[rt]+=val;
        if (mx[rt]==k) {
            if (same[rt]) {
                cnt[rt]=r-l+1;
            } else {
                pushDown(rt);
                update(l, mid, L, R, ls, 0);
                update(mid+1, r, L, R, rs, 0);
                cnt[rt]=cnt[ls]+cnt[rs];
            }
        }
    } else {
        pushDown(rt);
        if (L<=mid) update(l, mid, L, R, ls, val);
        if (mid<R) update(mid+1, r, L, R, rs, val);
        pushUp(rt);
    }
}
void update(int x, int y, int val) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, idd, id[top[x]], id[x], 1, val);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    // sum[id[x]]++, sum[id[y] + 1]--;
    update(1, idd, id[x], id[y], 1, val);
}
void init(int n) {
    for (int i=0; i<=n+100; i++) {
        son[i]=sz[i]=dep[i]=fa[i]=sum[i]=id[i]=top[i]=0;
        head[i]=0; 
    }
    idd=0; vcnt=0;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int TT=1; TT<=t; TT++) {
        printf("Case %d:\n", TT);
        scanf("%d", &n);
        init(n);
        for (int i=1, a, b; i<n; i++) {
            scanf("%d%d", &a, &b);
            add(a, b); add(b, a);
        }
        dfs1(1, 0); dfs2(1, 1);
        int q; scanf("%d", &q);
        build(1, idd, 1);
        for (; q--; ) {
            clr(1, idd, 1);
            scanf("%d", &k);
            for (int i=0, a, b; i<k; i++) {
                scanf("%d%d", &a, &b);
                update(a, b, 1);
            }
            printf("%d\n", cnt[1]);
        }
    }
    return 0;
}
