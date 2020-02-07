#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=3e5;
int a[maxn];
int b[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n)) {
        int cnt = 1, tmp;
        b[0] = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (tmp > b[cnt-1]) {
                b[cnt++] = tmp;
            } else {
                *upper_bound(b, b + cnt, tmp) = tmp;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}