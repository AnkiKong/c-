#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n, m, k;
        double p;
        scanf("%d%d%d%lf", &n, &m, &k, &p);
        printf("Case %d: %.10f\n", TT, n * k *p);
    }
    return 0;
}