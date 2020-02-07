#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=110;
int sgn(ll x) {
    return (x>0)-(x<0);
}
struct P {
    ll d[3];
    ll& operator[] (int x) {
        return d[x];
    }
    P(){}
    P(ll a, ll b, ll c) {
        d[0]=a, d[1]=b, d[2]=c;
    }
};
struct node {
    P x; 
    int y;
}p[maxn];
P operator + (P a, P b) {
    P c;
    for (int i=0; i<3; i++)
        c[i]=a[i]+b[i];
    return c;
}
P operator - (P a, P b) {
    P c;
    for (int i=0; i<3; i++)
        c[i]=a[i]-b[i];
    return c;
}
P operator * (int a, P b) {
    P c;
    for (int i=0; i<3;i++)
        c[i]=a*b[i];
    return c;
}
ll operator * (P a, P b) {
    return a[1]*b[2]-a[2]*b[1];
}
ll operator ^ (P a, P b) {
    return a[1]*b[1]+a[2]*b[2];
}
ll det (P a, P b, P c) {
    return (b-a)*(c-a);
}
struct L {
    P a, b;
    L(){}
    L(P aa, P bb) : a(aa), b(bb) {} 
};
bool onSeg(P p, L s) {
    return sgn(det(p, s.a, s.b))==0 && sgn((s.a-p)^(s.b-p))<=0;
}
vector<P> convex(vector<P> p) {
    vector<P> ans, S;
    for (int i=0; i<p.size(); i++) {
        while (S.size()>=2 && sgn(det(S[S.size()-2], S.back(), p[i]))<=0) {
            S.pop_back();
        }
        S.push_back(p[i]);
    }
    ans=S;
    S.clear();
    for (int i=(int)p.size()-1; ~i; i--) {
        while (S.size()>=2 && sgn(det(S[S.size()-2], S.back(), p[i]))<=0) {
            S.pop_back();
        }
        S.push_back(p[i]);
    }
    for (int i=1; i+1<S.size(); i++) {
        ans.push_back(S[i]);
    }
    return ans;
}
bool PointInPolygon(P p, vector<P> poly) {
    int cnt=0;
    for (int i=0; i<poly.size(); i++) {
        if (onSeg(p, L(poly[i], poly[(i+1)%poly.size()]))) return true;
        int k=sgn(det(poly[i], poly[(i+1)%poly.size()], p));
        int d1=sgn(poly[i][2]-p[2]);
        int d2=sgn(poly[(i+1)%poly.size()][2]-p[2]);
        if (k>0 && d1<=0 && d2>0) cnt++;
        if (k<0 && d2<=0 && d1>0) cnt--;
    }
    return cnt!=0;
}
bool SegmentIntersection(L l1, L l2) {
    ll c1=det(l1.a, l1.b, l2.a), c2=det(l1.a, l1.b, l2.b);
    ll c3=det(l2.a, l2.b, l1.a), c4=det(l2.a, l2.b, l1.b);
    if (sgn(c1)*sgn(c2)<0 && sgn(c3)*sgn(c4)<0) return true;
    if (sgn(c1)==0 && onSeg(l2.a, l1)) return true;
    if (sgn(c2)==0 && onSeg(l2.b, l1)) return true;
    if (sgn(c3)==0 && onSeg(l1.a, l2)) return true;
    if (sgn(c4)==0 && onSeg(l1.b, l2)) return true;
    return false;
}
bool ConvexHullDivide(vector<P> p1, vector<P> p2) {
    for (P a:p1)
        if (PointInPolygon(a, p2))
            return false;
    for (P a:p2)
        if (PointInPolygon(a, p1))
            return false;
    for (int i=0; i<p1.size(); i++)
        for (int j=0; j<p2.size(); j++)
            if (SegmentIntersection(L(p1[i], p1[(i+1)%p1.size()]), L(p2[j], p2[(j+1)%p2.size()])))
                return false;
    return true;
}
bool check(vector<P> p1, vector<P> p2) {
    vector<P> c1=convex(p1);
    vector<P> c2=convex(p2);
    return ConvexHullDivide(c1, c2);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int n; t--; ) {
        scanf("%d", &n);
        vector<P>p1, p2;
        for (int i=0, x, y, c; i<n; i++) {
            scanf("%d%d%d", &x, &y, &c);
            if (c==1) p1.push_back(P(1, x, y));
            else      p2.push_back(P(1, x, y));
        }
        if (check(p1, p2)) {
            printf("Successful!\n");
        } else {
            printf("Infinite loop!\n");
        }
    }
    return 0;
}