#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=4e4;
int n;
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
int da[maxn];
struct node {
    int sum, mx;
}tr[maxn<<2];
void pushUp(int rt) {
    tr[rt].sum = tr[rt<<1].sum + tr[rt<<1|1].sum;
    tr[rt].mx = max(tr[rt<<1].mx, tr[rt<<1|1].mx); 
}
void build(int l, int r, int rt) {
    int mid = (l + r) >> 1;
    if (l == r) {
        tr[rt].sum = da[l], tr[rt].mx = da[l];
    } else {
        build(l, mid, rt<<1); build(mid+1, r, rt<<1|1); pushUp(rt);
    }
}
void update(int l, int r, int rt, int val, int loc) {
    if (l == r && l == loc) tr[rt].sum = tr[rt].mx = val;
    else {
        int mid = (l + r) >> 1;
        if (loc <= mid) update(l, mid, rt<<1, val, loc);
        else update(mid+1, r, rt<<1|1, val, loc);
        pushUp(rt);
    }
}
int query(int l, int r, int L, int R, int rt, int ty) { // 0 mx, 1 sum
    if (L <= l && r <= R) return ty ? tr[rt].sum : tr[rt].mx;
    int lAns = (ty ? 0 : -inf), rAns = (ty ? 0 : -inf), mid = (l + r) >> 1;
    if (L <= mid) lAns = query(l, mid, L, R, rt<<1, ty);
    if (mid < R) rAns = query(mid+1, r, L, R, rt<<1|1, ty);
    return ty ? lAns + rAns : max(lAns, rAns);
}
// start ShuPou
int sz[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], top[maxn], idd;
void dfs1(int u, int f) {
    sz[u] = 1; fa[u] = f;
    for (int i = head[u]; i; i = nxt[i]) {
        if (f == to[i]) continue;
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
        if (to[i] != son[u] && to[i] != fa[u]) 
            dfs2(to[i], to[i]);
}
int query2(int x, int y, int ty) { // 0 mx, 1 sum
    int ans = ty ? 0 : -inf;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        if (ty) ans += query(1, n, id[top[x]], id[x], 1, ty);
        else ans = max(ans, query(1, n, id[top[x]], id[x], 1, ty));
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    if (ty) ans += query(1, n, id[x], id[y], 1, ty);
    else ans = max(ans, query(1, n, id[x], id[y], 1, ty));
    return ans;
}
// end ShuPou
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b); add(a, b); add(b, a);
    }
    dfs1(1, -1); dfs2(1, 1);
    for (int i = 1; i <= n; i++) scanf("%d", da + id[i]);
    build(1, n, 1);
    int q; scanf("%d", &q);
    char op[20]; int a, b;
    while (q--) {
        scanf("%s%d%d", op, &a, &b);
        if (op[1] == 'M') {
            printf("%d\n", query2(a, b, 0));
        } else if (op[1] == 'S') {
            printf("%d\n", query2(a, b, 1));
        } else {
            update(1, n, 1, b, id[a]);
        }
    }
    return 0;
}