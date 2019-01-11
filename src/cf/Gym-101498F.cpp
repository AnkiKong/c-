#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii std::pair<int, int>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 100;
map<int, int> pre, inq;
int da[maxn];
int nxt[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    int n, k, m;
    while (t--) {
        scanf("%d%d", &n, &k);
        pre.clear(); inq.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            da[i] = m; pre[m] = inf;
        }
        for (int i = n; i > 0; i--) {
            nxt[i] = pre[da[i]];
            pre[da[i]] = i;
        }
        int ans = 0, cnt = 0;
        priority_queue<pii > q;
        for (int i = 1; i <= n; i++) {
            int id = da[i];
            if (inq[id]) {
                q.push(make_pair(nxt[i], da[i]));
                pre[da[i]] = nxt[i];
            } else {
                if (cnt < k) {
                    q.push(make_pair(nxt[i], da[i]));
                    pre[da[i]] = nxt[i];
                    inq[da[i]] = 1;
                    cnt++;
                } else {
                    pii tmp;
                    while (!q.empty()) {
                        tmp = q.top(); q.pop();
                        if(tmp.first == pre[tmp.second]) break;
                    }
                    inq[tmp.second] = 0;
                    inq[da[i]] = 1;
                    q.push(make_pair(nxt[i], da[i]));
                    pre[da[i]] = nxt[i];
                }
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}