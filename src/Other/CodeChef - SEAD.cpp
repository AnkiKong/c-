#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int a[maxn], s[maxn];
int maxm[maxn][32];
void ST(int n) {
    for (int i = 1; i <= n; i++)
        maxm[i][0] = s[i];

    int k = log(n * 1.0) / log(2.0);

    for (int j = 1; j <= k; j++)
        for (int i = 1; i < n; i++) {
            if (i + (1 << j) - 1 > n) break;
            maxm[i][j] = max(maxm[i][j - 1], maxm[i + (1 << (j - 1))][j - 1]);
        }
}

int getAns(int x, int y) {
  int k = log(y - x + 1.0) / log(2.0);
  return max(maxm[x][k], maxm[y + 1 - (1 << k)][k]);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 1; i <= n; i++) {
        s[i] = a[i] - a[i-1];
    }
    ST(n);
    int m; scanf("%d", &m);
    int t, d;
    while (m--) {
        scanf("%d%d", &t, &d);
        int endd = upper_bound(a+1, a+n+1, t) - a - 1;
        int l = 1, r = endd;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (getAns(mid+1, endd) > d) l = mid+1;
            else r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}