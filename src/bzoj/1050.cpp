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
const int maxn=600;
struct node {
    int a, b, w;
    bool operator < (const node& s) const {
        return w < s.w;
    }
    void read() {
        scanf("%d%d%d", &a, &b, &w);
    }
};
node v[6000];
int f[maxn];
int fin(int a) {
    return f[a] == a ? a : f[a] = fin(f[a]);
}
void com(int a, int b) {
    a = fin(a), b = fin(b);
    if (a != b) f[a] = b;
}
void init(int s) {
    for (int i = 0; i <= s; i++) f[i] = i;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, s, t; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) v[i].read();
    sort(v, v + m);
    scanf("%d%d", &s, &t);
    init(n);
    for (int i = 0; i < m; i++) com(v[i].a, v[i].b);
    if (fin(s) != fin(t)) {
        printf("IMPOSSIBLE");
        return 0;
    }
    double ans = inf, tmp;
    int u, d;
    for (int i = 0; i < m; i++) {
        init(n);
        for (int j = i; j < m; j++) {
            com(v[j].a, v[j].b);
            if (fin(s) == fin(t)) {
                tmp = 1.0 * v[j].w / v[i].w;
                if (tmp < ans) ans = tmp, u = v[j].w, d = v[i].w;
                break;
            }
        }
    }
    int gcd = __gcd(u, d);
    u /= gcd, d /= gcd;
    if (d != 1) printf("%d/%d", u, d);
    else printf("%d", u);
    return 0;
}