#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=4e5;
int n, m;
int head[maxn], to[maxn], nxt[maxn], vcnt;
void add(int a, int b) {
    to[++vcnt] = b, nxt[vcnt] = head[a], head[a] = vcnt;
}
int Head[maxn], To[maxn], Nxt[maxn], Vcnt;
void Add(int a, int b) {
    To[++Vcnt] = b, Nxt[Vcnt] = Head[a], Head[a] = Vcnt;
}
stack<int> s;
int dfn[maxn], low[maxn], vis[maxn], ins[maxn], cnt;
int belong[maxn], Amount, counts[maxn];
void tarjan(int u) {
    vis[u] = 1; dfn[u] = low[u] = cnt++;
    ins[u] = 1; s.push(u);
    for (int i = head[u]; i; i = nxt[i]) {
        if (!vis[to[i]]) tarjan(to[i]), low[u] = min(low[u], low[to[i]]);
        else if (ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
    }
    int x = 0;
    if (dfn[u] == low[u]) {
        Amount++;
        while(x != u){
            x = s.top(); s.pop(); ins[x] = 0;
            belong[x] = Amount;
            counts[Amount]++;
        }
    }
}
int in[maxn];
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
    for (int i = 1; i <= n; i++) if (!vis[i]) tarjan(i);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = nxt[j]) {
            if (belong[i] != belong[to[j]] && !vis[to[j]]) {
                Add(belong[i], belong[to[j]]);
                in[belong[to[j]]]++; vis[belong[to[j]]] = 1;
            }
        }
        for (int j = head[i]; j; j = nxt[j]) {
            vis[belong[to[j]]] = 0;
        }
    }
    int ans = 0;

    for (int i = 1; i <= Amount; i++) {
        if (!in[i]) ans++;
    }
    for (int i = 1; i <= Amount; i++) {
        if (counts[i] == 1 && !in[i]) {
            bool flag = 1;
            for (int j = Head[i]; j; j = Nxt[j]) {
                if (in[To[j]] <= 1) flag = 0;
            }
            if (flag) {ans--; break;}
        }
    }
    printf("%.6f", 1.0 - 1.0 * ans / n);
    return 0;
}