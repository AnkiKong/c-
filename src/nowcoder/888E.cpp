#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
int n;
struct DSU {
    struct sto {
        int x, faX, sz;
    }rs[maxn<<3];
    int rsSz;
    int fa[maxn], sz[maxn];
    void init() {
        for (int i=0; i<=n; i++) sz[i]=1, fa[i]=i;
    }
    void undo(int top) {
        for (int i=rsSz; i>top; i--) {
            sto& a=rs[i];
            fa[a.x]=a.faX; sz[a.x]=a.sz;
        }
        rsSz=top;
    }
    int fin(int a) {
        while (a!=fa[a]) a=fa[a];
        return a;
    }
    void merge(int a, int b) {
        a=fin(a); b=fin(b);
        if (a==b) return;
        if (sz[a]>sz[b]) swap(a, b);
        rs[++rsSz]=sto{a, fa[a], sz[a]};
        rs[++rsSz]=sto{b, fa[b], sz[b]};
        sz[b]+=sz[a]; fa[a]=b;
    }
};
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
DSU dsu;
struct V {
    int u, v, l, r;
    void in() {
        cin >> u >> v >> l >> r;
    }
}v[maxn];
struct node {int l, r;};
node nw;
vector<node> mergeList[maxn<<3];
int ans;
void update(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) {
        mergeList[rt].push_back(nw);
    } else {
        if (L<=mid) update(l, mid, L, R, ls);
        if (mid<R) update(mid+1, r, L, R, rs);
    }
}
int lc[maxn<<3];
void dfs(int l, int r, int rt) {
    int tp=dsu.rsSz;
    for (node& a:mergeList[rt]) {
        dsu.merge(a.l, a.r);
    }
    if (l==r) {
        if (dsu.fin(1)==dsu.fin(n)) ans+=lc[r+1]-lc[l];
    } else {
        dfs(l, mid, ls);
        dfs(mid+1, r, rs);
    }
    dsu.undo(tp);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int m; cin >> n >> m;
    dsu.init();
    int tot=0;
    for (int i=0; i<m; i++) {
        v[i].in(); v[i].r++;
        lc[++tot]=v[i].l; lc[++tot]=v[i].r;
    }
    sort(lc+1, lc+1+tot);
    int top=unique(lc+1, lc+1+tot)-lc-1;
    for (int i=0; i<m; i++) {
        int tl=lower_bound(lc+1, lc+1+top, v[i].l)-lc;
        int tr=lower_bound(lc+1, lc+1+top, v[i].r)-lc;
        nw.l=v[i].u; nw.r=v[i].v;
        update(1, top, tl, tr-1, 1);
    }
    dfs(1, top, 1);
    cout << ans << endl;
    return 0;
}