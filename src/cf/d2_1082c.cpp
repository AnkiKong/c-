#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5 + 100;
multiset<int> da[maxn];
vector<ll> sum[maxn];
#define pii pair<int, int>
pii cnt[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i <= m; i++) {
        cnt[i].first = 0;
        cnt[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        cnt[a].first++;
        da[a].insert(b);
    }
    for (int i = 0; i <= m; i++) {
        ll ss = 0;
        for (auto aa = da[i].rbegin(); aa != da[i].rend(); aa++) {
            ss += *aa;
            sum[i].push_back(ss);
        }
    }
    sort(cnt, cnt + m + 1, greater<pii > ());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp = 0;
        for (int j = 0; j <= n; j++) {
            if (cnt[j].first < i) break;
            int idd = cnt[j].second;
            if (sum[idd][i-1] < 0) continue;
            tmp += sum[idd][i-1];
        }
        ans = max(ans, tmp);
    }
    printf("%lld", ans);
    return 0;
}