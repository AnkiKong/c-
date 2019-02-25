#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
typedef unsigned long long ull;
ull phi(ull a) {
    ull res = a;
    for (ull i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            res -= res / i;
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) res -= res / a;
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ull a; scanf("%llu", &a);
    ull ans = 0, j;
    for (ull i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            j = a / i;
            ans += i * phi(j);
            if (i != j) ans += j * phi(i);
        }
    }
    printf("%llu", ans);
    return 0;
}