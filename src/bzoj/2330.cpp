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
int n, k;
int head[maxn], to[maxn<<2], nxt[maxn<<2], val[maxn<<2], vcnt;
void add(int a, int b, int c) {
    to[++vcnt] = b; nxt[vcnt] = head[a], val[vcnt] = c; head[a] = vcnt;
}
ll dis[maxn];
bool inq[maxn];
int cirCheck[maxn];
int spfa() {
    queue<int> q;
    q.push(0); inq[0] = 1; dis[0] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop(); inq[x] = 0;
        for (int i = head[x]; i; i = nxt[i]) {
            if (dis[x] + val[i] > dis[to[i]]) {
                if (++cirCheck[to[i]] > n) return 0;
                if (!inq[to[i]]) q.push(to[i]), inq[to[i]] = 1;
                dis[to[i]] = dis[x] + val[i];
            }
        }
    }
    return 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0, x, a, b; i < k; i++) {
        scanf("%d%d%d", &x, &a, &b);
        switch (x) {
            case 1: add(a, b, 0), add(b, a, 0); break;
            case 2: add(a, b, 1); if(a == b) {printf("-1"); return 0;}break;
            case 3: add(b, a, 0); break;
            case 4: add(b, a, 1); if(a == b) {printf("-1"); return 0;}break;
            case 5: add(a, b, 0); break;
        }
    }
    for (int i = n; i; i--) add(0, i, 1);
    if (!spfa()) {
        printf("-1\n"); return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += dis[i];
    printf(lld "\n", ans);
    return 0;
}