#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=110;
int w[maxn][maxn];
double num[maxn][maxn], ans[maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    memset(w, 0x3f3f, sizeof(w));
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        w[a][b] = w[b][a] = c; num[a][b]++, num[b][a]++; 
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || j == k) continue;
                if (w[i][j] > w[i][k] + w[k][j]) {
                    w[i][j] = w[i][k] + w[k][j];
                    num[i][j] = num[i][k] * num[k][j];
                } else if (w[i][j] == w[i][k] + w[k][j]) {
                    num[i][j] += num[i][k] * num[k][j];
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || k == j) continue;
                if (w[i][j] == w[i][k] + w[k][j]) {
                    ans[k] += (num[i][k] * num[k][j]) / num[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) 
        printf("%.3f\n", ans[i]);
    return 0;
}