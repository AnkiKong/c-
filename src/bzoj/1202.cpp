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
const int maxn=200;
int v[maxn], f[maxn];
void init() {
    for (int i = 0; i < maxn; i++) f[i] = i;
    memset(v, 0, sizeof(v));
}
int fin(int a) {
    if (f[a] == a) return a;
    int t = fin(f[a]);
    v[a] += v[f[a]];
    f[a] = t;
    return t;
}
int flag;
void add(int a, int b, int c) {
    int fa = fin(a), fb = fin(b);
    if (fa != fb) {
        f[fa] = fb;
        v[fa] = v[b] - v[a] - c;
    } else if (v[b] - v[a] != c) flag = 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        init();
        int n, m; scanf("%d%d", &n, &m);
        flag = 1;
        for (int i = 0, a, b, c; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a-1, b, c);
        }
        if (flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}