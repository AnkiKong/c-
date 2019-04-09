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
const int maxn=4000;
const int maxm=100;
int start, stop;
int head[maxm], nxt[maxn], to[maxn], w[maxn], vcnt;
void _add(int a, int b, int c) {
    to[vcnt]=b; nxt[vcnt]=head[a]; w[vcnt]=c; head[a]=vcnt++;
}
void add(int a, int b, int c) {
    _add(a, b, c);
    _add(b, a, 0);
}
int dep[maxm];
bool bfs() {
    memset(dep, -1, sizeof(dep));
    queue<int> q;
    q.push(start);
    dep[start]=1;
    while (!q.empty()) {
        int x=q.front(); q.pop();
        for (int i=head[x]; ~i; i=nxt[i]) {
            int t=to[i];
            if (dep[t]==-1 && w[i]) {
                dep[t]=dep[x]+1;
                q.push(t);
            }
        }
    }
    return dep[stop]!=-1;
}
int dfs(int x, int flow) {
    if (x==stop) return flow;
    int ans=0, fl;
    for (int i=head[x]; ~i; i=nxt[i]) {
        int t=to[i];
        if (dep[t]==dep[x]+1 && w[i]) {
            fl=dfs(t, min(flow, w[i]));
            flow-=fl; ans+=fl;
            w[i]-=fl; w[i^1]+=fl;
            if (!flow) break;
        }
    }
    if (!ans) dep[x]=-1;
    return ans;
}
int num[maxn], state[maxn];
int mp[maxn];
void init() {
    start=0, stop=0;
    for (int i=1; i<=2520; i++) {
        int s=0;
        for (int j=1; j<11; j++) {
            if (i%j==0) s|=1<<j;
        }
        if (!num[s]) num[s]=++stop, state[stop]=s;
        mp[i]=num[s];
    }
}
int lim[maxm];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        start=0, stop=60;
        memset(head, -1, sizeof(head)); vcnt=0;
        memset(lim, 0, sizeof(lim));
        int n; scanf("%d", &n);
        for (int i=1, x; i<=2520; i++) {
            x=n/2520;
            if (n%2520>=i) x++;
            lim[mp[i]]+=x;
        }
        for (int i=1; i<=48; i++) {
            add(i+10, stop, lim[i]);
        }
        for (int i=1, x; i<11; i++) {
            scanf("%d", &x);
            if (x) {
                add(start, i, x);
                for (int j=1; j<=48; j++) {
                    if ((state[j]>>i)&1) add(i, j+10, x);
                }
            }
        }
        int ans=0;
        while (bfs()) {
            ans+=dfs(start, inf);
        }
        printf("%d\n",ans);
    }
    return 0;
}