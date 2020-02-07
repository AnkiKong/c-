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
const double eps = 1e-8;
struct node {
    double x, y;
    node operator+(node a) {return (node){(a.x+x)/2, (a.y+y)/2};}
    node operator-(node a) {return (node){x-a.x, y-a.y};}
    node operator/(double a) {return (node){x/a, y/a};}
    node rev() {return (node) {y, -x};}
};
node p[maxn];
double dis(node a, node b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
node center(node a, node b) {
    return (node) {(a.x+b.x)/2, (a.y+b.y)/2};
}
double sqr(double a) {
    return a * a;
}
node cal(double x, double y, double z, double u, double v, double w) {
    node t;
    t.x = (z*v-w*y)/(x*v-u*y); t.y = (z-t.x*x)/y;
    return t;
}
node center(node a, node b, node c) {
    double a1, a2, b1, b2, c1, c2;
    node ans;
    a1=2*(b.x-a.x),b1=2*(b.y-a.y),c1=sqr(b.x)-sqr(a.x)+sqr(b.y)-sqr(a.y);
    a2=2*(c.x-a.x),b2=2*(c.y-a.y),c2=sqr(c.x)-sqr(a.x)+sqr(c.y)-sqr(a.y);
    if(fabs(a1) < eps) { 
        ans.y=c1/b1; 
        ans.x=(c2-ans.y*b2)/a2; 
    } else if(fabs(b1) < eps) { 
        ans.x=c1/a1; 
        ans.y=(c2-ans.x*a2)/b2; 
    } else { 
        ans.x=(c2*b1-c1*b2)/(a2*b1-a1*b2); 
        ans.y=(c2*a1-c1*a2)/(b2*a1-b1*a2); 
    } 
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    srand(time(0));
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        // if (i>1) swap(p[rand()%(i-1)+1], p[i]);
    }
    random_shuffle(p+1, p+1+n);
    node o = p[1];
    double r = 0;
    for (int i = 2; i <= n; i++) if (dis(o, p[i]) > r + eps) {
        o = center(p[1], p[i]); r = dis(o, p[i]);

        for (int j = 1; j < i; j++) if (dis(o, p[j]) > r + eps){
            o = center(p[i], p[j]); r = dis(o, p[j]);

            for (int k = 1; k < j; k++) if (dis(o, p[k]) > r + eps) {
                o = center(p[i], p[j], p[k]); r = dis(o, p[k]);
            }
        }
    }
    printf("%.10f\n%.10f %.10f", r, o.x, o.y);
    return 0;
}