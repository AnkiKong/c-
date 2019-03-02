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
const int maxn=1e5 + 100;
const int maxm=1e6 + 100;
int n, m, mod;
int head[maxn], to[maxm<<2], nxt[maxm<<2], vcnt;
int head2[maxn];
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
void add2(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head2[a]; head2[a] = vcnt;
}
int dfn[maxn], low[maxn], bl[maxn], counts[maxn], scc, cnts;
bool ins[maxn], vis[maxn];
stack<int> s;
void tarjan(int u) {
    vis[u] = 1; ins[u] = 1; s.push(u);
    dfn[u] = low[u] = cnts++;
    for (int i = head[u]; i; i = nxt[i]) {
        if (!vis[to[i]]) tarjan(to[i]), low[u] = min(low[u], low[to[i]]);
        else if (ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
    }
    if (dfn[u] == low[u]) {
        scc++; int x = 0;
        while(x != u){
            x = s.top(); s.pop(); ins[x] = 0;
            bl[x] = scc; counts[scc]++;
        }
    }
}
int ind[maxn];
void rebuild() {
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = nxt[j]) {
            if (bl[i] != bl[to[j]]) {
                add2(bl[i], bl[to[j]]);
                ind[bl[to[j]]]++;
            }
        }
    }
}
int sz[maxn], ans[maxn];
int dpVis[maxn];
void dp() {
    queue<int> q;
    for (int i = 1; i <= scc; i++) {
        if (!ind[i]) q.push(i);
        sz[i] = counts[i]; ans[i] = 1;
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head2[x]; i; i = nxt[i]) {
            int v = to[i];
            ind[v]--;
            if (!ind[v]) q.push(v);
            if (dpVis[v] == x) continue;
            dpVis[v] = x;
            if (sz[x] + counts[v] > sz[v]) {
                sz[v] = sz[x] + counts[v];
                ans[v] = ans[x];
            } else if (sz[x] + counts[v] == sz[v]) {
                ans[v] = (ans[v] + ans[x]) % mod;
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) tarjan(i);
    rebuild();
    dp();
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= scc; i++) {
        if (sz[i] > ans1) ans1 = sz[i], ans2 = ans[i];
        else if (sz[i] == ans1) ans2 = (ans2 + ans[i]) % mod;
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}