#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=510;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    set<ll> vis;
    int n; scanf("%d", &n);
    ll a, b, ans=0, r;
    for (int i=0; i<n; i++) {
        scanf("%lld", &a);
        vis.insert(a);
    }
    int q; scanf("%d", &q);
    while (q--) {
        scanf("%lld%lld", &a, &b);
        b-=a; ans=0; r=*vis.begin()-1;
        for (auto s=vis.begin(); s!=vis.end(); s++) {
            if (*s>r) r=*s-1;
            ans+=*s+b-r;
            r=*s+b;
            s=vis.lower_bound(r);
        }
        printf("%lld ", ans);
    }
    return 0;
}