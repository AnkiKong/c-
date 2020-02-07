#include <bits/stdc++.h>
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
        int n; scanf("%d", &n);
        double tt = 1;
        int cnt = n, ans = 0;
        while (tt > 0.5) {
            cnt--; 
            tt = tt * cnt / n;
            ans++;
        }
        printf("Case %d: %d\n", TT, ans);
    }
    return 0;
}