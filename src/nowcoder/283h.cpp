#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn=5e4 + 10;
const int mod = 1e9 + 7;
list<pii > mp[maxn];
bool inq[maxn];
int dis[maxn];
map<ll, int> LtoI;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll st = 1;
    LtoI[1LL] = 0;
    for (int i = 1; i < 63; i++) {
        st *= 2;
        LtoI[st] = i;
    }
    int n, m, s, t;
    memset(dis, 0x3f3f, sizeof(dis));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v;
    ll len;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &u, &v, &len);
        mp[u].push_back(make_pair(v, LtoI[len]));
    }
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    dis[s] = 0;
    while (!q.empty()) {
        u = q.front(); q.pop();inq[u] = 0;
        for (auto aa : mp[u]) {
            int newLen = aa.second + dis[u];
            if (newLen < dis[aa.first]) {
                dis[aa.first] = newLen;
                if (!inq[aa.first]) inq[aa.first] = 1, q.push(aa.first);
            }
        }
    }
    if (dis[t] == 0x3f3f3f3f) {
        printf("-1\n");
    } else {
        ll ans = 1, a = 2;
        for ( ; dis[t]; dis[t] >>= 1, a = a * a % mod) {
            if (dis[t] & 1) ans = ans * a % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}