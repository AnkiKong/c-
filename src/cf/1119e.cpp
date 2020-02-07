#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e5+100;
int da[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    ll ans=0, sum=0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", da+i);
        int g=min(sum, 1LL*da[i]/2);
        ans+=g; da[i]-=2*g; sum-=g;
        ans+=da[i]/3;
        da[i]%=3;
        sum+=da[i];
    }
    printf("%lld", ans);
    return 0;
}