#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll a) {
    ll ans = 0;
    while (a) {
        a /= 5;
        ans += a;
    }
    return ans;
}
ll binary(ll cnt) {
    ll l = 1, r = 0x3fffffffffffffff, tmp, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (cal(mid) < cnt) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (cal(l) == cnt) 
        return l;
    return -1;
}
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    ll n;
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld", &n);
        ll ans = binary(n);
        if (ans == -1) {
            printf("Case %d: impossible\n", tt);
        } else {
            printf("Case %d: %lld\n", tt, ans);
        }
    }
    return 0;
}