#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1)|1
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
#define pii pair<int, int>
int head[maxn], nxt[maxn<<1], to[maxn<<1], vcnt;
multiset<int> mn[maxn], era[maxn];
void _add(int a, int b) {
    to[++vcnt]=b; nxt[vcnt]=head[a]; head[a]=vcnt;
}
void add(int a, int b) {
    _add(a, b); _add(b, a);
}
int son[maxn], mSon[maxn];
int sum, root;
bool vis[maxn];
void getRt(int x, int fa) {
    son[x]=1; mSon[x]=0;
    for (int i=head[x], t; i; i=nxt[i]) {
        if ((t=to[i])==fa || vis[t]) continue;
        getRt(t, x);
        son[x]+=son[t]; mSon[x]=max(son[t], mSon[x]);
    }
    mSon[x]=max(mSon[x], sum-son[x]);
    if (mSon[x]<mSon[root]) root=x;
}
int fa[maxn][20], trFa[maxn];
int dfn[maxn], LOG2[maxn];
void dfs_lca(int x, int f) {
    fa[x][0]=f; dfn[x]=dfn[f]+1;
    for (int i=1; i<20; i++) {
        if (!fa[x][i-1]) break;
        else fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for (int i=head[x], t; i; i=nxt[i]) {
        if ((t=to[i])==f) continue;
        dfs_lca(t, x);
    }
}
int lca(int a, int b) {
    if (dfn[a]<dfn[b]) swap(a, b);
    for (int d=dfn[a]-dfn[b], i=0; d; d>>=1, i++) {
        if (d&1) a=fa[a][i];
    }
    if (a==b) return a;
    for (int i=LOG2[dfn[a]]+1; ~i; i--) {
        if (fa[a][i]!=fa[b][i]) a=fa[a][i], b=fa[b][i];
    }
    return fa[a][0];
}
int dis(int x, int y) {
    return dfn[x]+dfn[y]-dfn[lca(x, y)]*2;
}
void getTree(int rt) {
    vis[rt]=1;
    for (int i=head[rt], t; i; i=nxt[i]) {
        if (vis[t=to[i]]) continue;
        root=0, sum=son[t];getRt(t, -1);
        trFa[root]=rt;
        getTree(root);
    }
}
int c[maxn];
void color(int u) {
    for (int i=u; i; i=trFa[i]) {
        mn[i].insert(dis(u, i));
    }
}
int query(int x, int y) {
    int ans=inf;
    if (!mn[x].empty()) {
        ans=*mn[x].begin()+dis(x, y);
    }
    if (trFa[x]) {
        ans=min(query(trFa[x], y), ans);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    LOG2[0]=-1;
    for (int i=1; i<maxn; i++) LOG2[i]=LOG2[i>>1]+1;
    int n, m; cin >> n >> m;
    for (int i=1, a, b; i<n; i++) {
        cin >> a >> b;
        add(a, b);
    }
    mSon[0]=inf, sum=n;
    getRt(1, -1);
    trFa[root]=0;
    dfs_lca(1, -1);
    getTree(root);
    color(1);
    // cout << "---" << lca(1, 5) << " " << dis(1, 5) << endl;
    for (int i=0, a, b; i<m; i++) {
        cin >> a >> b;
        if (a==1) {
            color(b);
        } else {
            cout << query(b, b) << endl;
        }
    }
    return 0;
}