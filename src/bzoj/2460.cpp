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
const int maxn=1e4;
struct node {
    ll x, y;
    bool operator < (const node a) const {
        return y > a.y;
    }
}da[maxn];
ll p[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf(lld lld, &da[i].x, &da[i].y);
    }
    sort(da, da+n);
    // printf("%d\n", da[0].y);
    ll ans=0;
    for (int i=0; i<n; i++) {
        for (int j=64; ~j; j--) {
            if ((da[i].x>>j)&1) {
                if (p[j]) da[i].x^=p[j];
                else {
                    p[j]=da[i].x; break;
                }
            }
        }
        if (da[i].x) ans+=da[i].y;
    }
    printf(lld, ans);
    return 0;
}