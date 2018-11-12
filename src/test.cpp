#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // char str[10000];
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(min(a/i, b/(n-i)), ans);
    }
    printf("%d", ans);
    return 0;
}