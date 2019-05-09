#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n, k, a, b; scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
    ll len=n*k;
    ll mn=0, mx=len;
    ll s1=a+1, s2=k+1-a;
    ll st=1, e1, e2;
    for (int i=0; i<=n; i++) {
        e1=st-b; e1 = e1 <= 0 ? e1+len : e1;
        e2=st+b; e2 = e2 > len ? e2-len : e2;
        ll len1=abs(s1-e1), len2=abs(s1-e2), len3=abs(s2-e1), len4=abs(s2-e2);
        ll gcd1=__gcd(len, len1), gcd2=__gcd(len, len2);
        ll gcd3=__gcd(len, len3), gcd4=__gcd(len, len4);
        mn=max(mn, gcd1); mn=max(mn, gcd2);
        mn=max(mn, gcd3); mn=max(mn, gcd4);
        mx=min(mx, gcd1); mx=min(mx, gcd2);
        mx=min(mx, gcd3); mx=min(mx, gcd4);
        st+=k;
    }
    printf("%lld %lld\n", len/mn, len/mx);
    return 0;
}