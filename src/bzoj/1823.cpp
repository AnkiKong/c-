#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int head[maxn], to[maxn], nxt[maxn], cnt;
void add(int a, int b) {
    to[cnt] = b, nxt[cnt] = head[a]; head[a] = cnt++;
}
int cal(char type, int num) {
    return (num << 1) + (type != 'm');
}
int dfn[maxn], low[maxn], vis[maxn], ins[maxn], dfns, Amount;
int belong[maxn], cnts[maxn];
stack<int> s;
void tarjan(int u) {
    vis[u] = ins[u] = 1; s.push(u);
    dfn[u] = low[u] = dfns++;
    for (int i = head[u]; ~i; i = nxt[i]) {
        if (!vis[to[i]]) tarjan(to[i]), low[u] = min(low[u], low[to[i]]);
        else if (ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
    }
    int x = 0;
    if (dfn[u] == low[u]) {
        Amount++;
        while (x != u) {
            x = s.top(); s.pop(); ins[x] = 0;
            belong[x] = Amount; cnts[Amount]++;
        }
    }
}
void init() {
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    while (!s.empty()) ins[s.top()] = 0, s.pop();
    Amount = cnt = dfns = 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    int n, m, num1, num2; char type1, type2;
    for (int TT = 1; TT <= T; TT++) {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 0, n1, n2; i < m; i++) {
            getchar();
            scanf("%c%d %c%d", &type1, &num1, &type2, &num2);
            n1 = cal(type1, num1); n2 = cal(type2, num2);
            add(n1^1, n2); add(n2^1, n1);
        }
        for (int i = 0; i < (n<<1); i++) {
            if (!vis[i]) tarjan(i);
        }
        bool flag = 1;
        for (int i = 0; i < (n<<1); i += 2) {
            if (belong[i] == belong[i^1]) {
                flag = 0; printf("BAD\n"); break;
            }
        }
        if (flag) printf("GOOD\n");
    }
    return 0;
}