#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int n, m;
int head[maxn], nxt[maxn], to[maxn], Vcnt;
void add(int a, int b) {
    to[++Vcnt] = b; nxt[Vcnt] = head[a], head[a] = Vcnt;
}
stack<int> s;
bool ins[maxn], vis[maxn];
int dfn[maxn], low[maxn], cnt;
int belong[maxn], counts[maxn], amount;
void tarjan(int u) {
    vis[u] = ins[u] = 1; s.push(u);
    dfn[u] = low[u] = cnt++;
    for (int i = head[u]; i; i = nxt[i]) {
        if (!vis[to[i]]) tarjan(to[i]), low[u] = min(low[to[i]], low[u]);
        else if (ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
    }
    if (low[u] == dfn[u]) {
        int x = 0;
        amount++;
        while(x != u){
            x = s.top(); s.pop();
            ins[x] = 0;
            belong[x] = amount;
            counts[amount]++;
        }        
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) tarjan(i);
    }
    // for (int i = 1; i <= n; i++) printf("%d ", belong[i]);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = nxt[j]) {
            if (belong[i] != belong[to[j]]) {
                vis[i] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= amount; i++) {
        if (!vis[i]) {
            if (ans) {ans = 0; break;}
            else ans = counts[i];
        }
    }
    printf("%d", ans);
    return 0;
}