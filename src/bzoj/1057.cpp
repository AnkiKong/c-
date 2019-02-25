#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2010;
int g[maxn][maxn];
int h[maxn][maxn];
int s[maxn], t[maxn];
int n, m;
int ans1, ans2;
void cal() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j]) h[i][j] = h[i-1][j] + 1;
            else h[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1, pos, top = 0; j <= m; j++) {
            for (pos = j; top && s[top] >= h[i][j]; top--) {
                ans1 = max(ans1, min(j-t[top], s[top]) * min(j-t[top], s[top]));
                ans2 = max(ans2, (j-t[top]) * s[top]);
                pos = t[top];
            }
            top++; s[top] = h[i][j], t[top] = pos;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", g[i] + j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] = (g[i][j] != ((i+j)&1));
        }
    }
    cal();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] ^= 1;
        }
    }
    cal();
    printf("%d\n%d", ans1, ans2);
    return 0;
}