#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=300000+100;
ll sum[maxn];
ll da[maxn];
ll cal(int l, int r) {
    return sum[r]-sum[l-1];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int n; t--; ) {
        scanf("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf("%lld", da+i);
            sum[i]=sum[i-1]+da[i];
        }
        ll ans=(n+1LL)*n/2;
        for (int i=1; i<=n; i++) {
            int l=i;
            while (cal(l, i)<2*da[i] && l) l--;
            l++;
            int r=i;
            for (int j=l; j<=i; j++) {
                while (cal(j, r)<2*da[i] && r<=n) r++;
                r--;
                ans-=r-i+1;
            }

        }
        printf("%lld\n", ans);
    }
    return 0;
}