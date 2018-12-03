#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
double dfs(double a, double b, double c, int level) {
    if (!level) return a * c;
    return dfs(a + 1, b, c * a / (a + b), level - 1) + dfs(a, b + 1, c * b / (a + b), level - 1);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 0; i < 15; i++)
        printf("%d %.10f %.10f\n", i, dfs(1, 1, 1, i), 1.0 * i / 2 + 1);
    // int n; scanf("%d", &n);
    // printf("%f", 1.0 * n / 2 + 1);
    return 0;
}