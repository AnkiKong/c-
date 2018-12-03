#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn =1e5 + 10;
ll fac[50];
ll cal(int s, int e) {
    ll ans = 1;
    for (int i = s; i <= e; i++) ans *= i;
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int t, m; scanf("%d%d", &t, &m);
        if (m > t || (t-m) & 1) {
            printf("0\n");
            continue;
        }
        if (!t && !m) {
            printf("1\n");continue;
        }
        ll son = 1LL << t;
        ll mother = cal(m + (t - m) / 2, t);
        mother /= cal(1, t - (t - m) / 2);
        ll gcd = __gcd(son, mother);
        printf("%lld/%lld\n", mother / gcd, son / gcd);
    }
    return 0;
}