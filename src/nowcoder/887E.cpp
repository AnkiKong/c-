#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e7;
struct node {
    ll cnt;
    int tag;
    node() {
        cnt=0; tag=0;
    }
}tr[maxn];
const int M=400010;
int loc[M<<2];
void update(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) {
        tr[rt].tag++; tr[rt].cnt+=(loc[r+1]-loc[l]);
    } else {
        node &nw=tr[rt], &lc=tr[ls], &rc=tr[rs];
        if (nw.tag) {
            lc.tag+=nw.tag; lc.cnt+=1LL*(loc[mid+1]-loc[l])*nw.tag;
            rc.tag+=nw.tag; rc.cnt+=1LL*(loc[r+1]-loc[mid+1])*nw.tag;
            nw.tag=0;
        }
        if (L<=mid) update(l, mid, L, R, ls);
        if (mid<R) update(mid+1, r, L, R, rs);
        nw.cnt=lc.cnt+rc.cnt;
    }
}
int query(int l, int r, ll k, int rt) {
    if (l==r) {
        return loc[l]+(k-1)/tr[rt].tag;
    } else {
        node &nw=tr[rt], &lc=tr[ls], &rc=tr[rs];
        if (nw.tag) {
            lc.tag+=nw.tag; lc.cnt+=1LL*(loc[mid+1]-loc[l])*nw.tag;
            rc.tag+=nw.tag; rc.cnt+=1LL*(loc[r+1]-loc[mid+1])*nw.tag;
            nw.tag=0;
        }
        if (lc.cnt>=k) return query(l, mid, k, ls);
        else return query(mid+1, r, k-lc.cnt, rs);
    }
}

int X[M], Y[M];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    int x1, x2, a1, b1, c1, m1; scanf("%d%d%d%d%d%d", &x1, &x2, &a1, &b1, &c1, &m1);
    int y1, y2, a2, b2, c2, m2; scanf("%d%d%d%d%d%d", &y1, &y2, &a2, &b2, &c2, &m2);
    X[1]=x1, X[2]=x2;
    Y[1]=y1, Y[2]=y2;
    for (int i=3; i<=n; i++) {
        X[i]=(1LL*a1*X[i-1]%m1+1LL*b1*X[i-2]%m1+c1)%m1;
        Y[i]=(1LL*a2*Y[i-1]%m2+1LL*b2*Y[i-2]%m2+c2)%m2;
    }
    int cntLc=1;
    for (int i=1; i<=n; i++) {
        if (X[i]>Y[i]) swap(X[i], Y[i]);
        X[i]++; Y[i]+=2;
        loc[cntLc++]=X[i]; loc[cntLc++]=Y[i];
    }
    sort(loc+1, loc+cntLc+1);
    cntLc=unique(loc, loc+cntLc)-loc;
    loc[cntLc+1]=loc[cntLc]+1;
    ll cnts=0;
    for (int i=1; i<=n; i++) {
        cnts+=Y[i]-X[i];
        X[i]=lower_bound(loc+1, loc+cntLc+1, X[i])-loc;
        Y[i]=lower_bound(loc+1, loc+cntLc+1, Y[i])-loc;
        update(1, cntLc, X[i], Y[i]-1, 1);
        printf("%d\n", query(1, cntLc, (cnts+1)/2, 1));
    }

    return 0;
}