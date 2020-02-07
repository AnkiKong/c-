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
const int maxn=1e6+100;
int da[maxn];
map<int, int> loc;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", da + i);
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (loc.count(da[i])) {
            for (int e = loc[da[i]]; l <= e; l++) {
                loc.erase(da[l]);
            }
        }
        loc[da[i]] = i;
        if (loc.end()->first == (int)loc.size()) {
            ans = max(ans, (int)loc.size());
        }
    }
    printf("%d\n", ans);
    return 0;
}