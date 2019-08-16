#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
struct node {
    int x, y, k, t;
    void in() {
        scanf("%d%d%d%d", &x, &y, &k, &t);
    }
}e[12];
int X[12], Y[12];
int n, m;
bool check(int x, int y) {
    for (int i=0; i<n; i++) {
        if ((abs(x-e[i].x)+abs(y-e[i].y))%e[i].k!=e[i].t) return false;
    }
    return true;
}
ll cal(int l, int r) {
    r-=l+1;
    if (r<0) return 0;
    return r/60+1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &n, &m);
        int cX=1, cY=1;
        X[cX++]=m+1, Y[cY++]=m+1;
        for (int i=0; i<n; i++) {
            e[i].in();
            X[cX++]=e[i].x, Y[cY++]=e[i].y;
        }
        sort(X+1, X+cX);
        sort(Y+1, Y+cY);
        ll ans=0;
        for (int i=0; i<cX-1; i++) if (X[i]<X[i+1]) {
            for (int j=0; j<cY-1; j++) if (Y[j]<Y[j+1]) {
                for (int x=0; x<60; x++) {
                    for (int y=0; y<60; y++) {
                        if (check(X[i]+x, Y[j]+y)) ans+=cal(X[i]+x, X[i+1])*cal(Y[j]+y, Y[j+1]);
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}