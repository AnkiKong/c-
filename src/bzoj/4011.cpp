#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
const int mod = 1e9 + 7;
struct node {
    int t, nxt;
};
int head[maxn], cnt;
int ind[maxn], deg[maxn];
int inv[maxn];
int dp[maxn];
node v[maxn<<1];
int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b&1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, x, y;
    memset(head, -1, sizeof(head));
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[cnt] = (node){b, head[a]};
        head[a] = cnt++; ind[b]++; deg[b]++;
    }
    ind[y]++;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = 1LL * ans * ind[i] % mod;
    }
    if (y == 1) {
        printf("%d", ans);
        return 0;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) q.push(i);
        inv[i] = qpow(ind[i], mod - 2);
    }
    dp[y] = 1LL * ans * inv[y] % mod;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        for (int i = head[tmp]; ~i; i = v[i].nxt) {
            if(--deg[v[i].t] == 0) q.push(v[i].t);
            dp[v[i].t] = (dp[v[i].t] + 1LL * dp[tmp] * inv[v[i].t] % mod) % mod;
        }
    }
    ans = (ans - dp[x] + mod) % mod;
    printf("%d", ans);
    return 0; 
}