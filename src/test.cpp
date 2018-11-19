#include <bits/stdc++.h>

// using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
char str[maxn];
int cnt[300];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, mx1 = 0, mx2 = 0, sum = 0, tmp;
    scanf("%d", &n);
    if (n < 3) {
        printf("-1");
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            sum += tmp;
            if (tmp >= mx1) {
                if (mx1 > mx2) mx2 = mx1;
                mx1 = tmp;
            } else if (tmp > mx2) {
                mx2 = tmp;
            }
            if (i > 1 && mx1 - mx2 < sum - mx1 - mx2) {
                printf("%d", i + 1);return 0;
            }
        }
    }
    printf("-1");

}