#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
#define pii pair<ll, ll>
const int maxn=3e5+100;
const int mod=1e9+7;
pii da[maxn];
multiset<ll> vis;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &da[i].second, &da[i].first);
    }
    sort(da, da+n, greater<pii >());
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += da[i].second;
        vis.insert(da[i].second);
        if (i >= k) {sum -= *vis.begin(); vis.erase(vis.begin());}
        ans = max(ans, sum * da[i].first);
    }
    // printf("%d", *vis.begin());
    printf("%lld\n", ans);
    return 0;
}