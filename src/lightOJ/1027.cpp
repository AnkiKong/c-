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
        int n, tmp; scanf("%d", &n);
        int passCnt = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (tmp > 0) passCnt++;
            sum += abs(tmp);
        }
        printf("Case %d: ", TT);
        if (!passCnt) {
            printf("inf\n");
        } else {
            int gcd = __gcd(passCnt, sum);
            printf("%d/%d\n", sum/gcd, passCnt/gcd);
        }
    }
    return 0;
}