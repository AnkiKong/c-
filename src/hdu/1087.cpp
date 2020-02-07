#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1100;
int a[maxn];
ll ans[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        ll aans = -0x3f3f3f3f;
        ans[0] = a[0];
        for (int i = 1; i < n; i++) {
            ans[i] = a[i];
            ll tmp = 0;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    tmp = max(tmp, ans[j] * 1LL);
                }
            }
            ans[i] += tmp;
            aans = max(aans, ans[i]);
        }
        printf("%lld\n", aans);
    }
    return 0;
}