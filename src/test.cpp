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
    auto as = [](int a) {
        int ans=0;
        for (int i=1; i<=a; i++) {
            if (__gcd(a, i)==1) ans+=i;
        }
        return ans;
    };
    auto ab = [] (int a) {
        int ans=a;
        for (int i=2; i*i<=a; i++) {
            if (a%i==0) {
                ans-=ans/i;
                while (a%i==0) a/=i;
            }
        }
        if (a>1) ans-=ans/a;
        return ans;
    };
    for (int i=1; i<20; i++) {
        printf("%d %d %d\n", i, as(i), ab(i));
    }
    return 0;
}