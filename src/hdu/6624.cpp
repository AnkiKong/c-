#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
ll num, den; // 
void continue_frac(ll a1, ll b1, ll a2, ll b2, ll& num, ll& den) {
    ll c1=a1/b1, d1=a1%b1;
    ll c2=a2/b2, d2=a2%b2;
    if (c1!=c2 || !d1 || !d2) {
        den=1, num=min(c1, c2)+1;
    } else {
        continue_frac(b1, d1, b2, d2, den, num);
        num+=c1*den;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ll p, x; scanf("%lld%lld", &p, &x);
        continue_frac(p, x, p, x-1, num, den);
        ll z=num*x-den*p;
        printf("%lld/%lld\n", z, num);
    }
    return 0;
}