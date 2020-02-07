#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int deg[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, s;
    scanf("%d%d", &n, &s);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        deg[a]++, deg[b]++;
    }
    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        if (deg[i] == 1) cnt++;
    }
    printf("%.16f", 2.0 * s / cnt);
    return 0;
}