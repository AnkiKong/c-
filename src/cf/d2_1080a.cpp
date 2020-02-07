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
    int n, k; scanf("%d%d", &n, &k);
    int sum = 0;
    sum += (n * 2) / k + ((n * 2) % k != 0);
    sum += (n * 5) / k + ((n * 5) % k != 0);
    sum += (n * 8) / k + ((n * 8) % k != 0);
    printf("%d\n", sum);
    return 0;
}