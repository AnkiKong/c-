#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const double eps = 1e-6;
double ax, ay, bx, by, cx, cy, dx, dy, p, q, r;
// const int maxn=;
double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double cal(double x, double y) {
    double lx = cx, ly = cy, rx = dx, ry = dy;
    double x1, x2, y1, y2;
    double t1, t2;
    while (fabs(lx - rx) > eps || fabs(ly - ry) > eps) {
        x1 = lx + (rx - lx) / 3; x2 = lx + (rx - lx) / 3 * 2;
        y1 = ly + (ry - ly) / 3; y2 = ly + (ry - ly) / 3 * 2;
        t1 = dis(ax, ay, x, y) / p + dis(x, y, x1, y1) / r + dis(x1, y1, dx, dy) / q;
        t2 = dis(ax, ay, x, y) / p + dis(x, y, x2, y2) / r + dis(x2, y2, dx, dy) / q;
        if (t1 > t2) {
            lx = x1, ly = y1;
        } else {
            rx = x2, ry = y2;
        }
    }
    return dis(ax, ay, x, y) / p + dis(x, y, lx, ly) / r + dis(lx, ly, dx, dy) / q;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &p, &q, &r);
    double lx = ax, ly = ay, rx = bx, ry = by;
    double x1, x2, y1, y2;
    double t1, t2;
    while (fabs(lx - rx) > eps || fabs(ly - ry) > eps) {
        x1 = lx + (rx - lx) / 3; x2 = lx + (rx - lx) / 3 * 2;
        y1 = ly + (ry - ly) / 3; y2 = ly + (ry - ly) / 3 * 2;
        t1 = cal(x1, y1); t2 = cal(x2, y2);
        if (t1 > t2) {
            lx = x1, ly = y1;
        } else {
            rx = x2, ry = y2;
        }
    }
    printf("%.2f", cal(lx, ly));
    return 0;
}