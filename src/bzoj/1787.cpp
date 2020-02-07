#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5e5+100;
int head[maxn];
int cnt = 1;
struct node {
    int u, nxt;
}v[maxn << 1];
void add(int a, int b) {
    v[cnt] = (node) {b, head[a]}; head[a] = cnt++;
}
int n, m; 
int f[maxn][20];
int dep[maxn];
void dfs(int u, int dept, int fa) {
    f[u][0] = fa;
    dep[u] = dept;
    for (int i = 1; i < 20; i++) {
        if (f[u][i-1] < 0) f[u][i] = -1;
        else f[u][i] = f[f[u][i-1]][i-1];
    }
    for (int i = head[u]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (to == fa) continue;
        dfs(to, dept + 1, u);
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 0, d = dep[a] - dep[b]; d; i++, d >>= 1) {
        if (d & 1) a = f[a][i];
    }
    if (a == b) return a;
    for (int i = log(n) + 1; i >= 0; i--) {
        if (f[a][i] != f[b][i]) a = f[a][i], b = f[b][i];
    }
    return f[a][0];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int a, b, c;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs(1, 0, -1);
    int t1, t2, t3, t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        t1 = lca(a, b), t2 = lca(a, c), t3 = lca(b, c);
        if (t1 == t2) t = t3;
        else if (t1 == t3) t = t2;
        else t = t1;
        printf("%d %d\n", t, dep[a] + dep[b] + dep[c] - dep[t1] - dep[t2] - dep[t3]);
    }
    return 0;
}