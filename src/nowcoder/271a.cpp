#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
// const int maxn=;
map<ll, ll> cnt;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n, m;
    ll sum = 0, tmp;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &tmp);
        sum += tmp;
        cnt[tmp]++;
    }
    queue<pll> q;
    q.push(make_pair(n, 1));
    if (sum != n) {
        printf("ham\n");
        return 0;
    }
    pll ttmp, tmp1, tmp2;
    // printf("%lld\n", *vis.begin());
    while (!q.empty()) {
        ttmp = q.front(); q.pop();
        if (ttmp.first < cnt.begin() -> first) {
            printf("ham\n"); return 0;
        }
        if (cnt.find(ttmp.first) != cnt.end()){
            ll delta = min(cnt[ttmp.first], ttmp.second);
            cnt[ttmp.first] -= delta;
            ttmp.second -= delta;
            if (cnt[ttmp.first] == 0) cnt.erase(ttmp.first);
        } else if (ttmp.first == 1) {
            printf("ham\n"); return 0;
        } 
        if (ttmp.second){
            ll tttmp = ttmp.first >> 1;
            if (tttmp == ttmp.first - tttmp) {
                q.push(make_pair(tttmp, ttmp.second << 2));
            } else {
                ll a1 = tttmp;
                ll a2 = ttmp.first - a1;
                if (a1) q.push(make_pair(a1, ttmp.second));
                if (a2) q.push(make_pair(a2, ttmp.second));
            }
            
        }
    }
    if (cnt.size()) {
        printf("ham\n");
    } else {
        printf("misaka\n");
    }
    return 0;
}