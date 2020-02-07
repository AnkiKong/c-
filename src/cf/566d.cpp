#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn = 300000 + 1000;
int f[maxn];
int n, m;
int fin(int a) {
    if (f[a] != a) return f[a] = fin(f[a]);
    return a;
}
void com(int a, int b) {
    int fa = fin(a);
    int fb = fin(b);
    if (fa != fb)  f[fb] = fa;
}
int check(int a, int b) {
    return fin(a) == fin(b);
}
void init() {
    for (int i = 0; i < 3e5 + 100; i++) f[i] = i;
}
int nxt[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    init();
    int a, b, o, tmp;
    for (int ii = 0; ii < m; ii++) {
        scanf("%d%d%d", &o, &a, &b);
        if (o == 1) {
            com(a, b);
        } else if (o == 2) {
            for (int i = a; i <= b; i++) {
                com(a, i);
                if (nxt[i]) {
                    tmp = nxt[i];
                    nxt[i] = b+1;
                    i = tmp;
                    continue;
                }
                nxt[i] = b+1;
            }
        } else {
            printf("%s\n", check(a, b) ? "YES" : "NO");
        }
    }
    return 0;
}