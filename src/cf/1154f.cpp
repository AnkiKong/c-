#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
#define pii pair<int, int>
ll v[maxn], sum[maxn];
ll dp[maxn];
vector<pii> pr;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; i++) scanf("%lld", v+i);
    sort(v+1, v+1+n);
    for (int i=1; i<=n; i++) sum[i]=sum[i-1]+v[i], dp[i]=sum[i];
    for (int i=0, a, b; i<m; i++) {
        scanf("%d%d", &a, &b);
        if (a>k) continue;
        pr.push_back(pii(a, b));
    }
    sort(pr.begin(), pr.end());
    for (int i=1, l; i<=k; i++) {
        for (pii a:pr) {
            if (a.first>i) break;
            l=i-a.first;
            dp[i]=min(dp[i], dp[l]+sum[i]-sum[l+a.second]);
        }
    }
    printf("%lld\n", dp[k]);
    return 0;
}