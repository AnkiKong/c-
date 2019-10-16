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
const int maxn=2e5+100;
int n;
struct mat {
    int a[5][5];
    mat() {
        memset(a, 0x3f, sizeof(a));
    }
    mat operator * (const mat &aa) const {
        mat ans;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                    ans.a[i][j]=min(ans.a[i][j], a[i][k]+aa.a[k][j]);
                }
            }
        }
        return ans;
    }
};
mat tr[maxn<<2];
char da[maxn];
void pushUp(int rt) {
    tr[rt]=tr[ls]*tr[rs];
}
void build (int l, int r, int rt) {
    if (l==r) {
        mat &nw = tr[rt];
        for (int i=0; i<5; i++) nw.a[i][i]=0;
        if (da[l]=='2') nw.a[0][0]=1, nw.a[0][1]=0;
        else if (da[l]=='0') nw.a[1][1]=1, nw.a[1][2]=0;
        else if (da[l]=='1') nw.a[2][2]=1, nw.a[2][3]=0;
        else if (da[l]=='9') nw.a[3][3]=1, nw.a[3][4]=0;
        else if (da[l]=='8') nw.a[3][3]=1, nw.a[4][4]=1;
    } else {
        build(l, mid, ls);
        build(mid+1, r, rs);
        pushUp(rt);
    }
}
mat query(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) return tr[rt];
    if (R<=mid) return query(l, mid, L, R, ls);
    if (mid<L) return query(mid+1, r, L, R, rs);
    return query(l, mid, L, R, ls)*query(mid+1, r, L, R, rs);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int q;
    cin >> n >> q;
    cin >> (da+1);
    reverse(da+1, da+1+n);
    build(1, n, 1);
    for (int l, r; q--; ) {
        cin >> l >> r;
        l=n-l+1, r=n-r+1;
        swap(l, r);
        mat ans=query(1, n, l, r, 1);
        cout << (ans.a[0][4]>n ? -1 : ans.a[0][4]) << "\n";
    }
    return 0;
}