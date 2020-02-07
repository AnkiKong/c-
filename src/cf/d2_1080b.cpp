#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int sum = (r - l + 1);
        int ans;
        if (sum & 1) {
            ans = (sum >> 1) * (l & 1 ? 1 : -1);
            ans += r * (r & 1 ? -1 : 1);
        } else {
            ans = (sum >> 1) * (l & 1? 1 : -1);
        }
        printf("%d\n", ans);
    }
    return 0;
}