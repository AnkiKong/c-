#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e5;
const int maxm=1e6 + 100;
int head[maxn], to[maxm<<1], nxt[maxm<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a], head[a] = vcnt;
}
int head2[maxn];
void add2(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head2[a]; head2[a] = vcnt;
}
ll f[maxn], g[maxn];
ll ma[maxn], pa[maxn];
int n;
bool inq[maxn];
void spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i), inq[i] = 1;
    while(!q.empty()){
        int tmp = q.front(); q.pop(); inq[tmp] = 0;
        if (f[tmp] <= g[tmp]) continue;
        for (int i = head2[tmp]; i; i = nxt[i]) {
            g[to[i]] -= f[tmp];
            g[to[i]] += g[tmp];
            if (!inq[to[i]]) q.push(to[i]), inq[to[i]] = 1;
        }
        f[tmp] = g[tmp];
    }
    
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    ll s, k;
    for (int i = 1, r; i <= n; i++) {
        scanf("%lld%lld%d", &s, &k, &r);
        ma[i] = k, pa[i] = s;
        for (int j = 1, a; j <= r; j++) {
            scanf("%d", &a);
            add2(a, i); add(i, a);
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i] = ma[i], g[i] = pa[i];
        for (int j = head[i]; j; j = nxt[j]) {
            g[i] += ma[to[j]];
        }
    }
    spfa();
    printf("%lld\n", f[1]);
    return 0;
}