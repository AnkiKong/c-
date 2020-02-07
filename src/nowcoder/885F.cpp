#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6000;
vector<int> mp[maxn];
int fa[maxn], vis[maxn];
int dfs(int u) {
    if (vis[u]) return 0;
    vis[u]=1;
    for (int a:mp[u]) {
        if (!fa[a] || dfs(fa[a])) {
            fa[a]=u;
            fa[u]=a;
            return 1;
        }
    }
    return 0;
}
bool vis2[maxn], isAns[maxn];
void dfs2(int u) {
    isAns[u]=1;
    for (int v:mp[u]) {
        if (vis2[v]) continue;
        vis2[v]=1;
        dfs2(fa[v]);
    }
}
int da[maxn];
bool isS[maxn];
vector<int> s, t;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", da+i);
        if (__builtin_popcount(da[i])&1) s.push_back(i), isS[i]=1;
        else t.push_back(i);
    }
    for (int i:s)
        for (int j:t)
            if (__builtin_popcount(da[i]^da[j])==1) 
                mp[i].push_back(j);
    int ans=0;
    for (int i=1; i<=n; i++) {
        if (isS[i] && !fa[i]) {
            memset(vis, 0, sizeof(vis));
            ans+=dfs(i);
        } 
    }
    for (int i=1; i<=n; i++) {
        if (isS[i] && !fa[i]) {
            dfs2(i);
        }
    }
    printf("%d\n", n-ans);
    for (int i=1; i<=n; i++) {
        if (isS[i]) {
            if (isAns[i])
                printf("%d ", da[i]);
        } else if (!vis2[i]) {
            printf("%d ", da[i]);
        } 
    }
    return 0;
}