#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
struct node {
    int t, nxt;
};
int head[maxn], cnt;
int n, m;
int c[maxn];
node ve[maxn];
void add(int a, int b) {
    ve[cnt] = (node) {b, head[a]};
    head[a] = cnt++;
}
int dp[maxn][2];
void dfs(int u, int f) {
    if (u <= n){
        dp[u][c[u]] = 0, dp[u][c[u]^1] = inf;
        return;
    }
    for (int i = head[u]; ~i; i = ve[i].nxt) {
        if (ve[i].t == f) continue;
        dfs(ve[i].t, u);
        dp[u][0] += min(dp[ve[i].t][0], dp[ve[i].t][1] + 1);
        dp[u][1] += min(dp[ve[i].t][1], dp[ve[i].t][0] + 1);
    }   
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &m, &n);
    for (int i  = 1; i <= n; i++) scanf("%d", c + i);
    int a, b;
    memset(head, -1 , sizeof(head));
    for (int i = 1; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs(m, -1);
    printf("%d", min(dp[m][0], dp[m][1]) + 1);
    return 0;
}