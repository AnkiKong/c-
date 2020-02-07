#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+100;
ll mx[maxn][2], mn[maxn][2];
ll mxx[maxn], mnn[maxn];
ll a[maxn];
vector<int> mp[maxn];
int son[maxn];
void dfs1(int u, int fa) {
    son[u]=0;
    for (int v:mp[u]) {
        if (v==fa) continue;
        dfs1(v, u); son[u]++;
        if (mn[v][0]+a[u]>mx[u][0]) mx[u][1]=mx[u][0], mx[u][0]=mn[v][0]+a[u];
        else if (mn[v][0]+a[u]>mx[u][1]) mx[u][1]=mn[v][0]+a[u];
        if (mx[v][0]+a[u]<mn[u][0]) mn[u][1]=mn[u][0], mn[u][0]=mx[v][0]+a[u];
        else if (mn[v][0]+a[u]<mn[u][1]) mn[u][1]=mx[v][0]+a[u];
    }
    if (son[u]==0) mn[u][0]=mn[u][1]=mx[u][0]=mx[u][1]=a[u];
}

void dfs2(int u, int fa) {
    ll tp;
    for (int v:mp[u]) {
        if (v==fa) continue;
        if (son[u]==1) mxx[v]=mnn[u]+a[v], mnn[v]=mxx[u]+a[v];
        else {
            if (mx[u][0]==mn[v][0]+a[u]) tp=mx[u][1];
            else tp=mx[u][0];
            if (u!=1) tp=max(tp, mxx[u]);
            mnn[v]=tp+a[v];
            if (mn[u][0]==mx[v][0]+a[u]) tp=mn[u][1];
            else tp=mn[u][0];
            if (u!=1) tp=min(tp, mnn[u]);
            mxx[v]=tp+a[v];
        }
        dfs2(v, u);
    }
}
void init(int n) {
    for (int i=0; i<=n; i++) {
        mp[i].clear();
        mx[i][0]=mx[i][1]=-linf;
        mn[i][0]=mn[i][1]=linf;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS; int t; cin >> t;
    ll tp;
    for (int n; t--; ) {
        cin >> n; init(n);
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) {
            cin >> tp; a[i]-=tp;
        }
        for (int i=1, a, b; i<n; i++) {
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs1(1, 0);
        mxx[1]=mnn[1]=a[1];
        dfs2(1, 0);
        ll ans=mn[1][0];
        for (int i=2; i<=n; i++) {
            if (son[i]) {
                ans=max(ans, min(mn[i][0], mnn[i]));
            } else {
                ans=max(ans, mnn[i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}