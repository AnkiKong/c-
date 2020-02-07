#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define mid ((l+r)>>1)
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=100000+100;
int ls[maxn<<6], rs[maxn<<6], mn[maxn<<6];
int tot;
void pushUp(int rt) {
    mn[rt]=min(mn[ls[rt]], mn[rs[rt]]);
}
void update(int lc, int l, int r, int& rt, int val) {
    if (!rt) rt=++tot;
    if (l==r) {
        mn[rt]=val;
    } else {
        if (lc<=mid) update(lc, l, mid, ls[rt], val);
        else update(lc, mid+1, r, rs[rt], val);
        pushUp(rt);
    }
}
int merge(int u, int v) {
    if (!u || !v) return v|u;
    int rt=++tot;
    ls[rt]=merge(ls[u], ls[v]);
    rs[rt]=merge(rs[u], rs[v]);
    mn[rt]=min(mn[u], mn[v]);
    return rt;
}
int query(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) {
        return mn[rt];
    } else {
        int ans=inf;
        if (L<=mid) ans=min(ans, query(l, mid, L, R, ls[rt]));
        if (mid<R) ans=min(ans, query(mid+1, r, L, R, rs[rt]));
        return ans;
    }
}
int dep[maxn], root[maxn], w[maxn];
vector<int> mp[maxn];
void dfs(int x, int fa) {
    update(dep[x], 1, maxn, root[x], w[x]);
    for (int a:mp[x]) {
        if (a==fa) continue;
        dep[a]=dep[x]+1;
        dfs(a, x);
        root[x]=merge(root[x], root[a]);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int n, r;
    cin >> n >> r;
    memset(mn, 0x3f3f, sizeof(mn));
    for (int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for (int i=1, a, b; i<n; i++) {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dep[r]=1;
    dfs(r, -1);
    int m; cin >> m;
    for (int p, q, last=0; m; m--) {
        cin >> p >> q;
        p=(p+last)%n+1;
        q=(q+last)%n;
        cout << (last=query(1, maxn, dep[p], min(dep[p]+q, maxn), root[p])) << "\n";
    }
    return 0;
}