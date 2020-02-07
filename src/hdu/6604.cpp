#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
struct tree{
    vector<int> G[maxn], E[maxn];
    int ind[maxn], dep[maxn];
    int f[maxn][20];
    int n, root, tot, a[maxn];
    void init(int _n) {
        n=_n;
        for (int i=0; i<=n; i++) G[i].clear(), ind[i]=0, dep[i]=0, E[i].clear();
        root=_n+1; tot=0;
    }
    void add(int a, int b) {
        G[a].push_back(b); E[b].push_back(a);
        ind[a]++;
    }
    void TP() {
        queue<int> q;
        for (int i=1; i<=n; i++) if (ind[i]==0) q.push(i), E[root].push_back(i), G[i].push_back(root);
        while (!q.empty()) {
            int u=q.front(); q.pop();
            a[++tot]=u;
            for (int a:E[u]) 
                if ((--ind[a])==0) q.push(a);
        }
    }
    int lca(int a, int b) {
        if (dep[a]>dep[b]) swap(a, b);
        for (int i=19; ~i; i--) if (dep[b]>dep[a] && dep[f[b][i]]>=dep[a]) b=f[b][i];
        for (int i=19; ~i; i--) if (f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
        return a==b ? a : f[a][0]; 
    }
    void pre() {
        dep[root]=1;
        for (int i=1; i<=n; i++) {
            int u=a[i], fa=-1;
            for (int v:G[u]) 
                fa = (fa==-1 ? v : lca(fa, v));
            dep[u]=dep[fa]+1; f[u][0]=fa;
            for (int i=1; i<20; i++) f[u][i]=f[f[u][i-1]][i-1];
        }
    }
}T;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int n, m; t--; ) {
        scanf("%d%d", &n, &m);
        T.init(n);
        for (int i=0, a, b; i<m; i++) {
            scanf("%d%d", &a, &b);
            T.add(a, b);
        }
        T.TP();
        T.pre();
        int q; scanf("%d", &q);
        for (int a, b; q--; ) {
            scanf("%d%d", &a, &b);
            printf("%d\n", T.dep[a]+T.dep[b]-T.dep[T.lca(a, b)]-1);
        }
    }
    return 0;
}