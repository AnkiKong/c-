#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const double eps=1e-7;
// const int maxn=;

struct Point{
    double x, y;
    Point(double a=0.0, double b=0.0) : x(a), y(b) {}
    Point operator - (const Point& a) const {
        return Point(x-a.x, y-a.y);
    }
    double dis() {
        return sqrt(x*x+y*y);
    }
    void print() {
        printf("%.12f %.12f ", x, y);
    }
};
bool check(double w, double h, double a, double b, double c, int _1, int _2, int _3) {
    Point A, B, C;
    if (w<a) B=Point(w, sqrt(a*a-w*w));
    else B=Point(a, 0);
    double angK=atan(B.y/B.x);
    double angA=acos((a*a+b*b-c*c)/(2*a*b));
    C=Point(b*cos(angK+angA), b*sin(angK+angA));
    if (C.x+eps>=0 && C.x-eps<=w && C.y+eps>=0 && C.y-eps<=h) {
        for (int i=1; i<4; i++) {
            if (i==_1) A.print();
            if (i==_2) B.print();
            if (i==_3) C.print();
        }
        puts("");
        return true;
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        double w, h, a, b, c;
        scanf("%lf%lf%lf%lf%lf", &w, &h, &a, &b, &c);
        if (check(w, h, a, b, c, 1, 2, 3)) continue;
        if (check(w, h, a, c, b, 2, 1, 3)) continue;
        if (check(w, h, b, a, c, 1, 3, 2)) continue;
        if (check(w, h, b, c, a, 3, 1, 2)) continue;
        if (check(w, h, c, a, b, 2, 3, 1)) continue;
        if (check(w, h, c, b, a, 3, 2, 1)) continue;
    }
    return 0;
}