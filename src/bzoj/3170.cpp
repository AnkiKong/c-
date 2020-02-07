#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
struct node {
    int x, y, id;
}da[maxn];
bool cmpX(node a, node b) {
    return a.x < b.x;
}
bool cmpY(node a, node b) {
    return a.y < b.y;
}
ll sumX[maxn], sumY[maxn];
ll rsumX[maxn], rsumY[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++) {
        scanf("%d%d", &a, &b);
        da[i].x = a + b, da[i].y = a - b;
    }
    sort(da+1, da+1+n, cmpX);
    for (int i = 1; i <= n; i++) {
        sumX[i] = sumX[i-1] + da[i].x;
        rsumX[n-i+1] = rsumX[n-i+2] + da[n-i+1].x;
        da[i].id = i;
    }
    sort(da+1, da+1+n, cmpY);
    for (int i = 1; i <= n; i++) {
        sumY[i] = sumY[i-1] + da[i].y;
        rsumY[n-i+1] = rsumY[n-i+2] + da[n-i+1].y;
    }
    ll tmp;
    double ans = 1e20;
    for (int i = 1; i <= n; i++) {
        tmp = 1LL * da[i].y * (i-1) - sumY[i-1] + rsumY[i+1] - 1LL * da[i].y * (n-i);
        int id = da[i].id;
        tmp += 1LL * (sumX[id]-sumX[id-1]) * (id-1) - sumX[id-1] + rsumX[id+1] - 1LL * (rsumX[id]-rsumX[id+1]) * (n-id);
        if (tmp < ans) ans = tmp;
    }
    printf("%.0f", ans/2);
    return 0;
}