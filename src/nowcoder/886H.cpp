#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
vector<int> mp[maxn];
int dis1[21][maxn];
int dis2[21][maxn];
int n;
void bfs(int x, int* dis) {
    queue<int> q;
    for (int i=0; i<=n; i++) dis[i]=-1;
    q.push(x); dis[x]=0;
    for (int nw; q.size(); q.pop()) {
        nw=q.front();
        for (int t:mp[nw]) {
            if (dis[t]==-1) {
                dis[t]=dis[nw]+1;
                q.push(t);
            }  
        }
    }
}
int dis[maxn], cnts[maxn*2];
bool vis[maxn];
int q1[maxn], q2[maxn];
ll bfs2(int* dis1, int* dis2) {
    int h1=1, ta1=0, h2=1, ta2=0;
    for (int i=0; i<=2*n; i++) cnts[i]=0;
    for (int i=1; i<=n; i++) {
        dis[i]=dis1[i]+dis2[i];
        cnts[dis[i]]++; vis[i]=0;
    }
    for (int i=1; i<=n*2; i++) cnts[i]+=cnts[i-1];
    for (int i=1; i<=n; i++) {
        ta1++; q1[cnts[dis[i]]--]=i;
    }
    for (int x; h1<=ta1 || h2<=ta2; ) {
        if (h2>ta2 || (h1<=ta1 && dis1[q1[h1]]+dis2[q1[h1]]<dis[q2[h2]])) {
            x=q1[h1++];
        } else {
            x=q2[h2++];
        }
        if (vis[x]) continue; vis[x]=1;
        for (int t:mp[x]) {
            if (dis[t]>dis[x]+1) {
                dis[t]=dis[x]+1;
                q2[++ta2]=t;
            }
        }
    }
    ll ans=0;
    for (int i=1; i<=n; i++) ans+=dis[i];
    return ans;
}
int sa[30], sb[30];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1, m; TT <= T; TT++) {
        scanf("%d%d", &n, &m);
        for (int i=0; i<=n; i++) mp[i].clear();
        for (int i=0, a, b; i<m; i++) {
            scanf("%d%d", &a, &b);
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        int aS, bS;
        scanf("%d", &aS);
        for (int i=1, a; i<=aS; i++) {
            scanf("%d", &a);
            bfs(a, dis1[i]);
        }
        scanf("%d", &bS);
        for (int i=1, b; i<=bS; i++) {
            scanf("%d", &b);
            bfs(b, dis2[i]);
        }
        ll ans=0;
        for (int i=1; i<=aS; i++) {
            for (int j=1; j<=bS; j++) {
                ans+=bfs2(dis1[i], dis2[j]);
            }
        }
        ll ans2=aS*bS*n;
        ll gcd=__gcd(ans, ans2);
        ans/=gcd; ans2/=gcd;
        if (ans2==1) printf("Case #%d: %lld\n", TT, ans);
        else printf("Case #%d: %lld/%lld\n", TT, ans, ans2);
    }
    return 0;
}