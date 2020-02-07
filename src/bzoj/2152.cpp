#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e4 + 100;
int head[maxn];
struct node {
    int u, w, nxt;
} v[maxn << 1];
int cnt;
void add(int a, int b, int c) {
    v[++cnt] = (node) {b, c, head[a]}; head[a] = cnt;
}
bool vis[maxn];
int son[maxn], mSon[maxn], root;
int n, sum;
void getRt(int x, int fa) {
    son[x] = 1, mSon[x] = 0;
    for (int i = head[x]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (vis[to] || to == fa) continue;
        getRt(to, x);
        son[x] += son[to];
        mSon[x] = max(mSon[x], son[to]);
    }
    mSon[x] = max(mSon[x], sum - son[x]);
    if (mSon[x] < mSon[root]) root = x;
}
int dep[maxn], ct[10];
void getDep(int u, int fa) {
    ct[dep[u]]++;
    for (int i = head[u]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (to == fa || vis[to]) continue;
        dep[to] = (dep[u] + v[i].w) % 3;
        getDep(to, u);
    }
}
int cal(int x, int now) {
    ct[0] = ct[1] = ct[2] = 0;
    dep[x] = now; getDep(x, -1);
    return ct[0] * ct[0] + ct[1] * ct[2] * 2;
}
int ans;
void solve(int x) {
    ans += cal(x, 0); vis[x] = 1;
    for (int i = head[x]; i; i = v[i].nxt) {
        int to = v[i].u;
        if (vis[to]) continue;
        ans -= cal(to, v[i].w);
        root = 0; sum = son[to]; getRt(to, -1);
        solve(root);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, a, b, c; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c); c %= 3;
        add(a, b, c); add(b, a, c);
    }
    mSon[0] = inf; sum = n;
    getRt(1, -1);
    solve(root);
    int gcd = __gcd(ans, n * n);
    printf("%d/%d\n", ans / gcd, n * n / gcd);
    return 0;
}