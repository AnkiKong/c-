#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5;
int cnt;
ll da[maxn];
void gen1(ll now, int last) {
    if (now > 2e12) return;
    if (now != 1) da[cnt++] = now;
    if (last == 4) gen1(now * 4, 4);
    gen1(now*7, 7); 
}
void gen2(ll now) {
    if (now  > 2e12) return;
    if (now) da[cnt++] = now;
    gen2(now*10+4);
    gen2(now*10+7);
}
int main() {
freopen("g.in", "r", stdin);
#ifdef LOCAL
    freopen("out.txt", "w", stdout);
#endif
    gen1(1, 4); gen2(0);
    sort(da, da+cnt);
    // printf("%d\n", cnt);
    cnt = unique(da, da+cnt) - da;
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ll a, b; scanf("%lld%lld", &a, &b);
        int ans = 0;
        for (int i = 0; da[i] <= b && i < cnt; i++) {
            if (da[i] < a) continue;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}