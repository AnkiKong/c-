#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e4;
struct node {
    double x, y, p;
} da[maxn], ans;
int n;
double minn = 99999999999999999LL;
inline double dis(node& a, node& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double rands() {
    return (rand() % 1000) / 1000.0;
}
inline double judge(node& now) {
    double res = 0;
    for (int i = 1; i <= n; i++) res += dis(da[i], now) * da[i].p;
    if (res < minn) minn = res, ans = now;
    return res;
}
void cal() {
    double T = 1e5, dE;
    node now = ans, ne;
    while(T > 1e-3){
        ne.x = now.x + T * (rands() * 2 - 1);
        ne.y = now.y + T * (rands() * 2 - 1);
        dE = judge(now) - judge(ne);
        if (dE>0 || exp(dE/T)>rands()) now = ne;
        T *= 0.99;
    }
    for (int i = 1; i <= 1000; i++) {
        ne.x = ans.x + T * (rands() * 2 - 1);
        ne.y = ans.y + T * (rands() * 2 - 1);
        judge(ne);
    }
    
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    srand(20002333);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf%lf", &da[i].x, &da[i].y, &da[i].p);
        ans.x += da[i].x, ans.y += da[i].y;
    }
    ans.x /= n, ans.y /= n;
    cal();
    printf("%.3f %.3f\n", ans.x, ans.y);
    return 0;
}