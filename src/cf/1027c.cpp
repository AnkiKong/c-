#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e6 + 100;
map<int, int> cnt;
int da[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n, tmp;
        scanf("%d", &n);
        cnt.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        int ct = 0;
        for (auto aa : cnt) {
            tmp = aa.second - (aa.second & 1);
            for (int j = 0; j < tmp; j++) da[ct++] = aa.first;
        }
        int loc;
        ll pp=1e5, ss=1;
        for (int i = 0; i < ct - 2; i+=2) {
            ll p = 1LL * da[i]*2 + da[i+2]*2, s = 1LL * da[i] * da[i+2];
            if (pp*pp*s > ss*p*p) {
                loc = i, pp = p, ss = s;
            }
        }
        printf("%d %d %d %d\n", da[loc], da[loc+1], da[loc+2], da[loc+3]);
    }
    return 0;
}