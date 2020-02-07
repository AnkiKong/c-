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
const int maxn=4000;
struct node {
    ll x, y;
}da[maxn], da2[maxn];
ll cal(node a, node b) {
    return a.x * b.y - b.x * a.y;
}
ll cmp1(node a, node b) {
    return cal(a, b) > 0;
}
ll cmp2(node a, node b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(lld lld, &da[i].x, &da[i].y);
    }
    sort(da+1, da+1+n, cmp2);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sumx = 0, sumy = 0;
        int cnt = 0;
        for (int j = i + 1; j <= n; j++) {
            sumx += da2[++cnt].x = da[j].x - da[i].x;
            sumy += da2[cnt].y = da[j].y - da[i].y;
        }
        sort(da2+1, da2+1+cnt, cmp1);
        for (int j = 1; j <= cnt; j++) {
            sumx -= da2[j].x;
            sumy -= da2[j].y;
            ans += (da2[j].x * sumy - da2[j].y * sumx);
        }
    }
    printf(lld "." lld, ans>>1, (ans&1)*5);
    // printf("%.1f\n", 1.0 * ans / 2);
    return 0;
}