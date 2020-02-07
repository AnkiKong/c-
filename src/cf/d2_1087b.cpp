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
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll aa;
    for (ll i = k - 1; i; i--) {
        if (n % i == 0) {
            aa = i;
            break;
        }
    }
    printf("%lld\n", n * k / aa + aa);
    return 0;
}