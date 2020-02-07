#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 100;
int cnt[maxn], aa[maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int ans = 0;
    int n, k;
    int a = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        aa[a]++; cnt[a]++;
    }
    a = 0;
    for (int i = 1; i <= k; i++) {
        if (cnt[i] > ans) ans = cnt[i], a = 1;
        else if (cnt[i] == ans) a++;
        if (aa[i]) {
            for (int j = i << 1; j <= k; j += i) {
                cnt[j] += aa[i];
            }
        }
    }
    printf("%d %d", ans, a);
    
    return 0;
}