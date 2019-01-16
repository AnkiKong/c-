#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
int da[maxn], nxt[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", da + i);
    }
    for (int i = 1; i <= n; i++) {
        if (da[i-1] != da[i]) nxt[i] = i - 1;
        else nxt[i] = nxt[i-1];
    }
    int a, b, c;
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        if (da[b] != c) {
            printf("%d\n", b);
        } else if (nxt[b] >= a) {
            printf("%d\n", nxt[b]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}