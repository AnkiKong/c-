#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5+10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 78294349;
const double eps = 1e-8;
const int maxn=1e4;
const int maxm=1e7;
char buf[100000],*p1=buf,*p2=buf;
inline char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x){
    char c=nc();x=0;
    if(c==EOF) return false;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    return true;
}
int start, stop;
int head[maxn], vcnt;
struct node {
    int nxt, to, f, w, fr;
}v[maxm];
void _add(int a, int b, int c, int ww) {
    // to[vcnt]=b; f[vcnt]=c; w[vcnt]=ww; nxt[vcnt]=head[a]; fr[vcnt] = a; head[a]=vcnt++;
    v[vcnt]=node{head[a], b, c, ww, a}; head[a]=vcnt++;
}
void add(int a, int b, int c, int ww) {
    _add(a, b, c, ww); _add(b, a, 0, -ww);
}
int dis[maxn], from[maxn];
bool vis[maxn];
int H[maxn];
#define pii pair<int,int>
bool dijk() {
    for (int i=0; i<=stop; i++) dis[i]=inf;
    priority_queue<pii, vector<pii>, greater<pii> > q; q.push(pii(0, start)); dis[start]=0;
    while (!q.empty()) {
        pii nw=q.top(); q.pop();
        int x=nw.second;
        // if (vis[x]) continue;
        // vis[x]=1;
        if (dis[x]<nw.first) continue;
        node tp;
        for (int i=head[x]; ~i; i=v[i].nxt) {
            tp=v[i];
            // t=v[i].to; ww=v[i].w;
            if (tp.f && dis[x]+tp.w+H[x]-H[tp.to] <dis[tp.to]) {
                dis[tp.to]=dis[x]+tp.w+H[x]-H[tp.to];
                from[tp.to]=i; q.push(pii(dis[tp.to], tp.to));
            }
        }
    }
    return dis[stop]!=inf;
}
int mcf() {
    int ans=0;
    for (int i=0; i<=stop; i++) H[i]=0;
    while (dijk()) {
        int x = inf;
        for (int i=0; i<=stop; i++) H[i]+=dis[i];
        for (int i = stop; i; i=v[from[i]].fr) {
            x = min(x, v[from[i]].f);
        }
        ans+=x*H[stop];
        for (int i = stop, t; i; i=v[t].fr) {
            t=from[i];
            // ans += x * v[t].w;
            v[t].f -= x; v[t^1].f += x;
        }
    }
    return ans;
}
void init(int n) {
    for (int i=0; i<=n; i++) {
        head[i]=-1; vcnt=0;
    }
}
int da[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    rea(t);
    for (int TT=1, n, k; TT<=t; TT++) {
        // scanf("%d%d", &n, &k);
        rea(n); rea(k);
        start=0, stop=n*2+2; int start2=stop-1;
        init(stop);
        add(start, start2, k, 0);
        // for (int i=1; i<=n; i++) add(start2, i, 1, 0);
        for (int i=1; i<=n; i++) {
            // scanf("%d", da+i);
            rea(da[i]);
            add(i, i+n, 1, -da[i]);
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<i; j++) {
                if (da[i]>=da[j]) 
                    add(j+n, i, 1, 0);
            }
        }
        for (int i=1; i<=n; i++) add(start2, i, 1, 0), add(i+n, stop, 1, 0);
        printf("%d\n", -mcf());
    }
    return 0;
}
