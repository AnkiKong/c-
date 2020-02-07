#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
char str[maxn], str2[10];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n;
        scanf("%d%s%s", &n, str, str2);
        ll ans=0, last=0;
        for (int i=0; i<n; i++) {
            if (str[i]==str2[0]) {
                ans+=1LL*(i-last+1)*(n-i);
                last=i+1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}