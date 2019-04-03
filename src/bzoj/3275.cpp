#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3100;
const int maxm=2e6;
int head[maxn], to[maxm], nxt[maxm], w[maxm], vcnt;
void _add(int a, int b, int c) {
    to[vcnt]=b; w[vcnt]=c; nxt[vcnt]=head[a]; head[a]=vcnt++;
}
void add(int a, int b, int c) {
    _add(a, b, c);
    _add(b, a, 0);
}
int start, stop;
int dep[maxn];
bool bfs() {
    memset(dep, -1, sizeof(dep));
    queue<int> q;
    q.push(start); dep[start]=0;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for (int i=head[x]; ~i; i=nxt[i]) {
            if (w[i] && dep[to[i]]==-1) {
                dep[to[i]]=dep[x]+1;
                q.push(to[i]);
            }
        }
    }
    return dep[stop]!=-1;
}
int dfs(int u, int flow) {
    if (u == stop) return flow;
    int res=0;
    for (int i=head[u]; ~i; i=nxt[i]) {
        int t=to[i];
        if (w[i] && dep[t]==dep[u]+1) {
            int f=dfs(t, min(flow, w[i]));
            flow-=f;
            w[i]-=f; w[i^1]+=f;
            res+=f;
            if (!flow) break;
        }
    }
    if (~res) dep[u]=-1;
    return res;
}
int mxf() {
    int ans=0;
    while (bfs()) {
        ans+=dfs(start, inf);
    }
    return ans;
}
#define pii pair<int, int>
bool check(pii a, pii b) {
    ll tmp=1LL*a.first*a.first + 1LL*b.first*b.first;
    ll tmp2=sqrt(tmp);
    return tmp2*tmp2==tmp && __gcd(a.first, b.first)==1;
}
vector<pii > l, r;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    memset(head, -1, sizeof(head));
    start=0, stop=n+1;
    int sum=0;
    for (int i=1, a; i<=n; i++) {
        scanf("%d", &a);
        sum+=a;
        if (a&1) {
            add(start, i, a);
            l.push_back(pii(a, i));
        } else {
            add(i, stop, a);
            r.push_back(pii(a, i));
        }
    }
    for (int i=l.size(); ~i; i--) {
        pii a= l[i];
        for (int j=r.size(); ~j; j--) {
            pii b=r[j];
            if (check(a, b)) {
                add(a.second, b.second, inf);
            }
        }
    }
    printf("%d\n", sum-mxf());
    return 0;
}