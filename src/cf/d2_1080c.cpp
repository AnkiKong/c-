#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ll n, m; scanf("%d%d", &n, &m);
        ll x1, x2, x3, x4;
        ll y1, y2, y3, y4;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &x2, &x3, &x4, &y1, &y2, &y3, &y4);
        ll b = n * m >> 1;
        ll w = n * m - b;
        if ((x1 + x2) & 1) {
            ll deta = (x3 - x1) * (x4 - x2) >> 1;
            b -= (deta >> 1) + (deta & 1);
            w += (deta >> 1) + (deta & 1);
        } else {
            ll deta = (x3 - x1) * (x4 - x2) >> 1;
            b -= (deta >> 1) + (deta & 1);
            w += (deta >> 1) + (deta & 1);
        }
        if (y1 >= x1 && y1 <= x3 && y2 >= x2 && y2 <= x4) {
            ll nx, ny;
            nx = min(x3, y3);
            ny = max(x2, y2);
            
        }
    }
    return 0;
}