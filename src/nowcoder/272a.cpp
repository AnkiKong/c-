#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
const int mod = 1e9 + 7;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = 0;
    if (k >= n) {
        n = k;
        ll tmp = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans + tmp) % mod;
            tmp = tmp * 2 % mod;
        } 
    }else {
        ll tmp = 1;
        k = n - k;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1 || (i > k / 2 && i < n - k / 2 - 1))
                ans = (ans + tmp) % mod;
            tmp = tmp * 2 % mod;
        }
    }
    printf("%lld", ans);
    return 0;
}