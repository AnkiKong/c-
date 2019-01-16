#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif // LOCAL
#define pii pair<double, double>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9+7;
const int maxn=2e5 + 100;
int ai[maxn], bi[maxn], ci[maxn];
struct node {
    int f, to, nxt, from;
    ll cost;
};
node ve[maxn << 2];
int head[maxn];
int cnt, stop, start;
int n, m;
void add(int u, int v, int w, ll w2) {
    ve[cnt] = (node) {w, v, head[u], u, w2};
    head[u] = cnt++;
    ve[cnt] = (node) {0, u, head[v], v, -w2};
    head[v] = cnt++;
}
int checkPri(int a) {
    if (a == 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}
ll dis[maxn];
bool inq[maxn];
int pre[maxn];
bool spfa() {
    for (int i = start; i <= stop; i++) dis[i] = linf, inq[i] = 0, pre[i] = -1;
    dis[start] = 0, inq[start] = 1;
    queue<int> q; q.push(start);
    while (!q.empty()) {
        int now = q.front(); q.pop(); inq[now] = 0;
        for (int i = head[now]; ~i; i = ve[i].nxt) {
            node& tmp = ve[i];
            if (tmp.f && dis[tmp.to] > dis[now] + tmp.cost) {
                dis[tmp.to] = dis[now] + tmp.cost;
                pre[tmp.to] = i;
                if (!inq[tmp.to]) inq[tmp.to] = 1, q.push(tmp.to); 
            }
        }
    }
    return pre[stop] != -1;
}
int mcmf(ll& nowCost) {
    int flow = 0; nowCost = 0;
    while (spfa()) {
        int minn = inf;
        for (int i = pre[stop]; ~i; i = pre[ve[i].from]) {
            if (minn > ve[i].f) minn = ve[i].f;
        }
        for (int i = pre[stop]; ~i; i = pre[ve[i].from]) {
            ve[i].f -= minn, ve[i^1].f += minn;
            nowCost += minn * ve[i].cost;
        }
        flow += minn;
    }
    return flow;
}
ll costMap[210][210];
bool has[210][210];
bool check(int maxFlow) {
    memset(head, -1, sizeof(head)); cnt = 0;
    add(start, 1, 2*maxFlow, 0);
    for (int i = 1; i <= n; i++) {
        add(1, i+1, bi[i], 0);
        add(i+n+1, stop, bi[i], 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (has[i][j]) add(i+1, j+n+1, inf, -costMap[i][j]);
        }
    }
    ll cost = 0;
    ll f = mcmf(cost);
    if (f < maxFlow*2 || cost>0) return 0;
    return 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    start = 0, stop = 2 * n + 2;
    for (int i = 1; i <= n; i++) scanf("%d", ai+i);
    for (int i = 1; i <= n; i++) scanf("%d", bi+i);
    for (int i = 1; i <= n; i++) scanf("%d", ci+i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i!=j && ai[i]%ai[j]==0 && checkPri(ai[i]/ai[j])) 
                costMap[i][j] = costMap[j][i] = 1LL * ci[i] * ci[j], has[i][j] = has[j][i] = 1;
        }
    }
    int l = 0, r = inf;
    int ans = 0;
    while (l < r) {
        int mid = (l+r)>>1;
        if (check(mid)) {
            ans = mid, l = mid+1;
        } else {
            r = mid;
        }
    }
    printf("%d\n", ans);
    return 0;
}