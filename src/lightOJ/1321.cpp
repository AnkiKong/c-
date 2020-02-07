#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn=110;
list<pair<int, double> > mp[maxn];
bool inq[maxn];
double p[maxn];
void init(int n) {
    memset(inq, 0, sizeof(inq));
    memset(p, 0, sizeof(p));
    for (int i = 0; i <= n; i++) mp[i].clear();
}
void spfa() {
    inq[0] = 1;
    queue<int> q;
    q.push(0);
    p[0] = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        inq[tmp] = 0;
        for (auto a : mp[tmp]) {
            if (p[tmp] * a.second > p[a.first]) {
                p[a.first] = p[tmp] * a.second;
                if (!inq[a.first]) inq[a.first] = 1, q.push(a.first);
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n, m, s, k;
        scanf("%d%d%d%d", &n, &m, &s, &k);
        init(n);
        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            mp[a].push_back(make_pair(b, 1.0 * c / 100));
            mp[b].push_back(make_pair(a, 1.0 * c / 100));
        }
        spfa();
        printf("Case %d: %.10f\n", TT, 2.0 * s * k / p[n - 1]);
    }
    return 0;
}