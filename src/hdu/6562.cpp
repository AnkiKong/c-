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
const int mod=1e9+7;
struct node {
    ll sum, len;
    ll tagR, tagL, tagLen;
} tr[maxn<<2];
void build(int l, int r, int rt) {
    tr[rt].sum=tr[rt].tagL=tr[rt].tagR=0;
    tr[rt].tagLen=1;
    if (l==r) {
        tr[rt].len=1;
    } else {
        build(l, mid, ls);
        build(mid+1, r, rs);
        tr[rt].len=tr[ls].len+tr[rs].len;
    }
}
void add(ll &a, ll b) {
    a+=b; if (a>=mod) a-=mod;
}
void pushDn(int rt, int l, int r) {
    if (tr[rt].tagLen) {
        node &lc=tr[ls], &rc=tr[rs], &nw=tr[rt];
        lc.sum=(lc.sum*nw.tagLen%mod + nw.tagR*(mid-l+1)%mod + nw.tagL*lc.len%mod*nw.tagLen%mod)%mod;
        rc.sum=(rc.sum*nw.tagLen%mod + nw.tagR*(r-mid)%mod + nw.tagL*rc.len%mod*nw.tagLen%mod)%mod;
        lc.len=lc.len*nw.tagLen%mod*nw.tagLen%mod;
        rc.len=rc.len*nw.tagLen%mod*nw.tagLen%mod;
        lc.tagL=(nw.tagL*lc.tagLen%mod + lc.tagL)%mod;
        rc.tagL=(nw.tagL*rc.tagLen%mod + rc.tagL)%mod;
        lc.tagR=(lc.tagR*nw.tagLen%mod + nw.tagR)%mod;
        rc.tagR=(rc.tagR*nw.tagLen%mod + nw.tagR)%mod;
        lc.tagLen=lc.tagLen*nw.tagLen%mod;
        rc.tagLen=rc.tagLen*nw.tagLen%mod;
        nw.tagL=nw.tagR=0;
        nw.tagLen=1;
    }
}
void update(int l, int r, int L, int R, ll val, int rt) {
    node& nw=tr[rt];
    if (L<=l && r<=R) {
        nw.sum=((r-l+1)*val%mod+nw.sum*10%mod+nw.len*val*10%mod)%mod;
        nw.len=nw.len*100%mod;
        nw.tagL=(nw.tagL+nw.tagLen*val%mod)%mod;
        nw.tagR=(nw.tagR*10+val)%mod;
        nw.tagLen=nw.tagLen*10%mod;
    } else {
        pushDn(rt, l, r);
        if (L<=mid) update(l, mid, L, R, val, ls);
        if (mid<R) update(mid+1, r, L, R, val, rs);
        nw.len=(tr[ls].len+tr[rs].len)%mod;
        nw.sum=(tr[ls].sum+tr[rs].sum)%mod;
    }
}
ll query(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) {
        return tr[rt].sum;
    } else {
        pushDn(rt, l, r);
        ll ans=0;
        if (L<=mid) ans+=query(l, mid, L, R, ls);
        if (mid<R) ans+=query(mid+1, r, L, R, rs);
        return ans%mod;
    }
}
char op[10];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        printf("Case %d:\n", TT);
        int n, m; scanf("%d%d", &n, &m);
        build(1, n, 1);
        for (int i=0, l, r, val; i<m; i++) {
            scanf("%s", op);
            if (op[0]=='w') {
                scanf("%d%d%d", &l, &r, &val);
                update(1, n, l, r, val, 1);
            } else {
                scanf("%d%d", &l, &r);
                printf("%lld\n", query(1, n, l, r, 1));
            }
        }
    }
    return 0;
}