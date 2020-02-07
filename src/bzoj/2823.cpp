#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6 + 100;
const double eps = 1e-6;
struct node {
    double x, y;
};
node point[maxn];
double dis(node a, node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
node center(node a, node b) {
    return (node) {(a.x + b.x) / 2, (a.y + b.y)/2 };
}

// 外心
double sqr(node b) {
    return b.x * b.x + b.y * b.y;
}
node cal(double x, double y, double z, double u, double v, double w) {
    node t;
    t.x = (z*v-w*y)/(x*v-u*y); t.y = (z-t.x*x)/y;
    return t;
}
node center(node u, node v, node w) {
    double p = sqr(u) / 2, q = sqr(v) / 2, t = sqr(w) / 2;
    return cal(u.x - v.x, u.y - v.y, p-q, u.x-w.x, u.y-w.y, p-t);
}
// 外心 -end
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    srand(time(0));
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &point[i].x, &point[i].y);
        if (i > 1) swap(point[i], point[rand()%(i-1)+1]);
    }
    node o = point[1];
    double r = 0;
    for (int i = 2; i <= n; i++) if(dis(o, point[i]) > r + eps) {
        o = center(point[1], point[i]); r = dis(o, point[i]);

        for (int j = 1; j < i; j++) if (dis(o, point[j]) > r + eps) {
            o = center(point[i], point[j]); r = dis(o, point[i]);

            for (int k = 1; k < j; k++) if (dis(o, point[k]) > r + eps) {
                o = center(point[i], point[j], point[k]); r = dis(o, point[i]);
            }
        }
    }
    printf("%.2f %.2f %.2f", o.x, o.y, r);
    return 0;
}