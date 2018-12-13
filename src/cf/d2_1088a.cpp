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
    int x;
    scanf("%d", &x);
    int a = 2, b;
    for (b = x / a; b <= x; b++) {
        if (b % a == 0 && a * b > x && a <= x && b <= x) {
            printf("%d %d", b, a);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}