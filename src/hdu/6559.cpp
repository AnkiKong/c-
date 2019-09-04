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
double myFabs(double a) {
    if (a<0) a=-a;
    return a;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS; int t; cin >> t;
    double h, r, x0, y0, z0, vx, vy, vz;
    for (int T=1; t--; T++) {
        cin >> r >> h >> x0 >> y0 >> z0 >> vx >> vy >> vz;
        double a=(vx*vx+vy*vy)-r*r*vz*vz/h/h;
        double b=2*(x0*vx+y0*vy)-r*r*2*z0*vz/h/h+2*r*r*vz/h;
        double c=(x0*x0+y0*y0-r*r)-r*r*z0*z0/h/h+2*r*r*z0/h;
        double ans1=1e18, ans2=1e18;

        // if (fabs(a)<eps) {
        //     ans1=-c/b;
        // } else {
        double deta=sqrt(b*b-4*a*c);
        ans1=(-b-deta)/(2*a); {
            double x=x0+ans1*vx;
            double y=y0+ans1*vy;
            double z=z0+ans1*vz;
            if (z>h || z<0) ans1=1e18;
        }
        ans2=(-b+deta)/(2*a); {
            double x=x0+ans2*vx;
            double y=y0+ans2*vy;
            double z=z0+ans2*vz;
            if (z>h || z<0) ans2=1e18;
        }
        
        //     ans1=fabs(ans1); ans2=fabs(ans2);
        //     if (ans1==0.0) ans1=1e18;
        //     if (ans2==0.0) ans2=1e18;
        // }
        printf("Case %d: %.10f\n", T, min(ans1, ans2));
    }
    return 0;
}