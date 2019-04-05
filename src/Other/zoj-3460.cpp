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
const int maxm=3e5;
int head[maxn], to[maxm], nxt[maxm], Tcnt;
void add(int a, int b) {
    to[++Tcnt] = b; nxt[Tcnt] = head[a]; head[a] = Tcnt;
}
int vis[maxn], fa[maxn];
int dfs(int u) {
    for (int i = head[u], t; i; i = nxt[i]) {
        t = to[i];
        if (vis[t]) continue;
        vis[t] = 1;
        if (!fa[t] || dfs(fa[t])) {
            fa[t] = u;
            return 1;
        }
    }
    return 0;
}
int N;
int getAns() {
    int ans = 0;
    memset(fa, 0, sizeof(fa));
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        ans += dfs(i);
    }
    return ans;
}
struct node {
    double x, y;
}da1[60], da2[60];
double cost[maxn][60];
#define sqr(x) ((x)*(x))
double dis(int i, int j) {
    return sqrt(sqr(da2[i].x-da1[j].x)+sqr(da2[i].y-da1[j].y));
}
#undef sqr
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    double t1, t2, v;
    while(~scanf("%d%d%lf%lf%lf", &n, &m, &t1, &t2, &v)){
        t1 /= 60; N = m;
        for (int i = 1; i <= m; i++) scanf("%lf%lf", &da1[i].x, &da1[i].y);
        for (int i = 1; i <= n; i++) scanf("%lf%lf", &da2[i].x, &da2[i].y);
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= m; k++) 
                    cost[i*m+j][k] = dis(i, k) / v + t1 * j + t2 * (j-1);
        double l = 0, r = 1e12, mid;
        while(r - l > 1e-7){
            mid = (l + r) / 2;
            memset(head, 0, sizeof(head));
            Tcnt = 0;
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= m; j++)
                    for (int k = 1; k <= m; k++)
                        if (cost[i*m+j][k] <= mid) 
                            add(k, i*m+j);
            if (getAns() == m) r = mid;
            else l = mid;
        }
        printf("%.6f\n", r);
    }
    
    return 0;
}