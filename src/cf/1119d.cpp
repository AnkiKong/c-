#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
ll s[maxn];
ll b[maxn];
ll sum[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", s+i);
    }
    sort(s, s+n);
    s[n]=2.5e18;
    for (int i=0; i<n; i++) {
        b[i]=s[i+1]-s[i];
    }
    sort(b, b+n);
    for (int i=1; i<=n; i++) sum[i]=b[i-1]+sum[i-1];
    int q; scanf("%d", &q);
    ll l, r, ans, d;
    while (q--) {
        scanf("%lld%lld", &l, &r);
        d=r-l+1;
        int pos=upper_bound(b, b+n, d)-b;
        ans=sum[pos]+(n-pos)*d;
        printf("%lld ", ans);
    }
    return 0;
}