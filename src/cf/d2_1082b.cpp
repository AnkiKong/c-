#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5 + 100;
char str[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d%s", &n, str);
    int ans = 0;
    int tmp0 = 0, tmp1 = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // int tmp = 0;
        if (str[i] == 'G') {
            tmp0++; tmp1++; sum++;
        } else {
            ans = max(tmp0 + 1, ans);
            ans = max(ans, tmp1);
            tmp1 = tmp0 + 1;
            tmp0 = 0;
        }
    }
    ans = max(ans, tmp0);
    ans = max(ans, tmp1);
    if (ans > sum) ans = sum;
    printf("%d\n", ans);
    return 0;
}