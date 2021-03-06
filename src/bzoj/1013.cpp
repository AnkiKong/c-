#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
double a[12][12];
int n;
void gauss() {
    for (int i = 1; i <= n; i++) {
        int r = i;
        for (int j = i + 1; j <= n; j++) 
            if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
        for (int j = 1; j <= n + 1; j++) swap(a[i][j], a[r][j]);
        for (int j = 1; j <= n; j++) if (j != i) {
            double rate = a[j][i] / a[i][i];
            for (int k = i; k <= n + 1; k++) {
                a[j][k] -= a[i][k] * rate;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i][n+1] /= a[i][i];
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", a[i] + j);
        }
    }    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][n+1] += a[i][j]*a[i][j] - a[i+1][j] * a[i+1][j];
            a[i][j] = 2 * (a[i][j] - a[i+1][j]);
        }
    }
    gauss();
    for (int i = 1; i <= n; i++) {
        printf("%.3f ", a[i][n+1]);
    }
    return 0;
}