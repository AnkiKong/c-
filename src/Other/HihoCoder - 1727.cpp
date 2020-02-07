#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
ll a1[62], a2[62];
struct node {
    ll p[62];
    void clear() {
        memset(p, 0, sizeof(p));
    }
}tr[maxn<<2];
ll da[maxn];
ll check(ll a, ll* p) {
    for (int i=60; ~i; i--) {
        if (p[i]>0 && ((a>>i)&1)) a^=p[i];
    }
    return a;
}
void add(ll a, ll* p) {
    a=check(a, p);
    if (!a) return;
    for (int i=60; ~i; i--) {
        if ((a>>i)&1) {
            p[i]=a;
            return;
        }
    }
}
void build (int l, int r, int rt) {
    if (l==r) {
        tr[rt].clear();
        add(da[l], tr[rt].p);
    } else {
        build(l, mid, ls);
        build(mid+1, r, rs);
        tr[rt]=tr[ls];
        for (int i=0; i<=60; i++) {
            if (tr[rs].p[i]) 
                add(tr[rs].p[i], tr[rt].p);
        }
    }
}
void update(int l, int r, int rt, int loc, ll val) {
    if (l==r && l==loc) {
        tr[rt].clear();
        add(val, tr[rt].p);
    } else {
        if (loc<=mid) update(l, mid, ls, loc, val);
        else update(mid+1, r, rs, loc, val);
        tr[rt]=tr[ls];
        for (int i=0; i<=60; i++) {
            if (tr[rs].p[i]) 
                add(tr[rs].p[i], tr[rt].p);
        }
    }
}
void query(int l, int r, int L, int R, int rt, ll* p) {
    if (L<=l && r<=R) {
        for (int i=60; ~i; i--) {
            if (tr[rt].p[i]) add(tr[rt].p[i], p);
        }
    } else {
        if (L<=mid) query(l, mid, L, R, ls, p);
        if (mid<R) query(mid+1, r, L, R, rs, p);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++) scanf("%lld", da+i);
    build(1, n, 1);
    for (ll o, a, b, c, d; q; q--) {
        scanf("%lld", &o);
        if (o==1) {
            scanf("%lld%lld", &a, &b);
            update(1, n, 1, (int)a, b);
        } else {
            scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
            memset(a1, 0, sizeof(a1));
            query(1, n, a, b, 1, a1);
            memset(a2, 0, sizeof(a2));
            query(1, n, c, d, 1, a2);
            int t1=0, t2=0;
            for (int i=60; ~i; i--) {
                if (a1[i]&&check(a1[i], a2)) t1=1;
                if (a2[i]&&check(a2[i], a1)) t2=1;
            }
            if (!t1 && !t2) printf("0\n");
            else if (t1 && !t2) printf("1\n");
            else if (t2 && !t1) printf("2\n");
            else printf("3\n");
        }
    }
    return 0;
}