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
const int maxn=2e5+100;
const int M=maxn<<2;
int xy[M], yz[M], mn[M], mx[M], ans[M], tag[M];
int da[maxn];
void pushUp(int rt) {
    xy[rt]=max(xy[ls], xy[rs]);
    xy[rt]=max(xy[rt], mx[ls]-mn[rs]*2);
    yz[rt]=max(yz[ls], yz[rs]);
    yz[rt]=max(yz[rt], mx[rs]-mn[ls]*2);
    mx[rt]=max(mx[ls], mx[rs]);
    mn[rt]=min(mn[ls], mn[rs]);
    ans[rt]=max(ans[ls], ans[rs]);
    ans[rt]=max(ans[rt], max(xy[ls]+mx[rs], mx[ls]+yz[rs]));
}
void pushDn(int rt) {
    if (tag[rt]) {
        xy[ls]-=tag[rt]; yz[ls]-=tag[rt];
        mn[ls]+=tag[rt]; mx[ls]+=tag[rt];
        tag[ls]+=tag[rt];
        xy[rs]-=tag[rt]; yz[rs]-=tag[rt];
        mn[rs]+=tag[rt]; mx[rs]+=tag[rt];
        tag[rs]+=tag[rt];
        tag[rt]=0;
    }
}
void build(int l, int r, int rt) {
    if (l==r) {
        mn[rt]=mx[rt]=da[l];
        xy[rt]=yz[rt]=-da[l];
        ans[rt]=-inf;
    } else {
        build(l, mid, ls);
        build(mid+1, r, rs);
        pushUp(rt);
    }
}
void update(int l, int r, int L, int R, int val, int rt) {
    if (L<=l && r<=R) {
        tag[rt]+=val;
        mx[rt]+=val; mn[rt]+=val;
        xy[rt]-=val; yz[rt]-=val;
    } else {
        pushDn(rt);
        if (L<=mid) update(l, mid, L, R, val, ls);
        if (mid<R) update(mid+1, r, L, R, val, rs);
        pushUp(rt);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    n=(n-1)*2;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') da[i+1]=da[i]+1;
        else da[i+1]=da[i]-1;
    }
    build(1, n, 1);
    cout << ans[1] << endl;
    int l, r;
    while (q--) {
        cin >> l >> r;
        update(1, n, l, n, s[l-1]=='(' ? -2 : 2, 1);
        update(1, n, r, n, s[r-1]=='(' ? -2 : 2, 1);
        swap(s[l-1], s[r-1]);
        cout << ans[1] << endl;
    }
    return 0;
}