#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 100;
bool vis[maxn];
bool vis2[maxn / 10];
int p[maxn];
int cnt;
void pri() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) p[cnt++] = i;
        for (int j = 0; j < cnt && 1LL * i * p[j] < maxn; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    pri();
    int t; scanf("%d", &t);
    int kase = 1;
    while (t--) {
        ll a, b; scanf("%lld%lld", &a, &b);
        memset(vis2, 0, sizeof(vis2));
        for (int i = 0; i < cnt && 1LL * p[i] * p[i] <= b; i++) {
            ll start = max(a / p[i] * p[i], 1LL * p[i] * p[i]);
            for (ll j = start; j <= b; j += p[i]) if (j >= a) vis2[j - a] = 1;
        }
        int ans = 0;
        for (int j = 0; j <= b - a; j++) {
            if (!vis2[j]) ans++;
        }
        if (a == 1) ans--;
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}