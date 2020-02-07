#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e5;
vector<int> mp[maxn];
bool isI[maxn], sIsI[maxn];
int sz[maxn], fa[maxn], dep[maxn], w[maxn];
ll a[maxn];
void dfs(int u, int fa) {
    dep[u]=dep[fa]+1;
    w[u]=u; sz[u]=1;
    int sum=0, pos=-1;
    for (int v:mp[u]) {
        if (v==fa) continue;
        dfs(v, u);
        if (!sIsI[v]) continue;
        sIsI[u]=1; sum++; pos=w[v];
    }
    if (!sIsI[u]) return;
    if (!isI[u] && sum==1) {
        if (isI[pos]) ::fa[pos]=u;
        else {
            w[u]=pos;
            sz[pos]++;
        }
    } else {
        isI[u]=1;
        for (int v:mp[u]) {
            if (v==fa || !sIsI[v]) continue;
            ::fa[w[v]]=u;
        }
    }
}

ll query(int ty, int u, int v, int k) {
    ll mn=1e18, mx=-1e18, sum=0;
    while (1) {
        if (dep[u]<dep[v]) swap(u, v);
        switch (ty) {
            case 1:a[u]+=k; break;
            case 2:a[u]^=k; break;
            case 3:if(a[u]>=k) a[u]-=k; break;
            case 4:sum+=a[u]*sz[u]; break;
            case 5:sum^=(sz[u]&1)?a[u]:0; break;
            case 6:mx=max(mx, a[u]); mn=min(mn, a[u]); sum=mx-mn; break;
            case 7:mn=min(mn, abs(a[u]-k)); sum=mn; break;
        }
        if (u==v) break;
        u=fa[u];
    }
    return sum;
}
int que[2010][4];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int t; cin >> t;
    for (int n, m; t--; ) {
        cin >> n >> m;
        for (int i=0; i<=n; i++) mp[i].clear(), isI[i]=sIsI[i]=0, a[i]=0;
        for (int i=1, a, b; i<n; i++) {
            cin >> a >> b;
            mp[a].push_back(b); 
            mp[b].push_back(a);
        }
        for (int i=0; i<m; i++) {
            int *nw=que[i];
            for (int j=0; j<3; j++) cin >> nw[j];
            if (nw[0]<=3 || nw[0]==7) cin >> nw[3];
            isI[nw[1]]=isI[nw[2]]=1;
            sIsI[nw[1]]=sIsI[nw[2]]=1;
        }
        dfs(1, 0);
        for (int i=0; i<m; i++) {
            int *nw=que[i];
            ll ans=query(nw[0], nw[1], nw[2], nw[3]);
            if (nw[0]>3) cout << ans << "\n";
        }
    }
    return 0;
}