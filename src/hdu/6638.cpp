#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
const int inf=0x3f3f3f3f;
const int maxn=2100;
struct node {
    ll s, sl, sr, sn;
    void cl() {
        s=sl=sr=sn=0;
    }
    void add(ll val) {
        s+=val; sl+=val; sr+=val; sn+=val;
    }
    void update(node& l, node& r) {
        s=l.s+r.s;
        sl=max(l.sl, l.s+r.sl);
        sr=max(r.sr, l.sr+r.s);
        sn=max(max(l.sn, r.sn), l.sr+r.sl);
    }
}tr[maxn<<2];
void build(int l, int r, int rt) {
    tr[rt].cl();
    if (l==r) return;
    build(l, mid, ls);
    build(mid+1, r, rs);
}
void update(int l, int r, int lc, ll val, int rt) {
    if (l==r) {
        tr[rt].add(val);
    } else {
        if (lc<=mid) update(l, mid, lc, val, ls);
        else update(mid+1, r, lc, val, rs);
        tr[rt].update(tr[ls], tr[rs]);
    }
}
ll query() {
    return tr[1].sn;
}
int X[maxn], Y[maxn];
struct P {
    int x, y, val;
    void in() {
        scanf("%d%d%d", &x, &y, &val);
    }
    bool operator < (const P& a) const {
        return x<a.x;
    }
}p[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n; scanf("%d", &n);
        for (int i=0; i<n; i++) {
            p[i].in();
            X[i]=p[i].x, Y[i]=p[i].y;
        }
        int cX, cY;
        sort(X, X+n); cX=unique(X, X+n)-X;
        sort(Y, Y+n); cY=unique(Y, Y+n)-Y;
        for (int i=0; i<n; i++) {
            p[i].x=lower_bound(X, X+cX, p[i].x)-X+1;
            p[i].y=lower_bound(Y, Y+cY, p[i].y)-Y+1;
        }
        sort(p, p+n);
        // build(1, cY, 1);
        int start=0;
        ll ans=0;
        for (int i=1; i<=cX; i++) {
            while (p[start].x<i && start<n) start++;
            build(1, cY, 1);
            for (int j=i, k=start; j<=cX && k<n; j++) {
                while (k<n && p[k].x<=j) update(1, cY, p[k].y, p[k].val, 1), k++;
                ans=max(ans, query());
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}