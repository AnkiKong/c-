#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=200;
int da[maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", da + i);
    }
    for (int i = 2; i < n; i++) {
        if (da[i-2] == 1 && da[i - 1] == 0 && da[i] == 1) {
            da[i] = 0; ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}