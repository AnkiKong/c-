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
const int maxn=1e6+100;
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
ll sum[maxn], cnt[maxn];
int n;
void dfs1(int u, int f) {
    sum[u] = 0, cnt[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == f) continue;
        dfs1(to[i], u);
        cnt[u] += cnt[to[i]];
        sum[u] += sum[to[i]] + cnt[to[i]];
    }
}
void dfs2(int u, int f) {
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == f) continue;
        sum[to[i]] = sum[u] - cnt[to[i]] + n - cnt[to[i]];
        dfs2(to[i], u);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs1(1, 0); dfs2(1, 0);
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (sum[ans] < sum[i]) ans = i;
    }
    printf("%d", ans);
    return 0;
}