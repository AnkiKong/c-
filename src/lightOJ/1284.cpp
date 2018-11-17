#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
double cal(int a, int b) {
    return 1.0 - 1.0 * ((a - 1) * (a - 1) + (b - a) * (b - a)) / b / b;
}
double Mpow(double a, int b) {
    double ans;
    for (ans = 1; b; b >>= 1, a *= a) {
        if (b & 1) ans *= a;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int x, y, z, k;
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d%d%d", &x, &y, &z, &k);
        double ans = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                for (int h = 1; h <= z; h++) {
                    double tmp = cal(i, x) * cal(j, y) * cal(h, z);
                    ans += 0.5 - 0.5 * Mpow(1 - 2 * tmp, k);
                }
            }
        }
        printf("Case %d: %.10f\n", TT, ans);
    }
    return 0;
}