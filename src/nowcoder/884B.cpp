#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int inf=0x3f3f3f3f;
const int maxn=5e4+100;
void ins(uint* p, uint x) {
    for (int i=31; ~i; i--) {
        if ((x>>i)&1) {
            if (p[i]) x^=p[i];
            else {
                p[i]=x; return;
            }
        }
    }
}
uint tr[maxn<<2][32];
uint x[32], y[32];
void merge(int rt, int a, int b) {
    for (int i=0; i<32; i++) x[i]=y[i]=tr[a][i];
    for (int i=0; i<32; i++) {
        uint u=tr[b][i], k=0;
        if (!u) continue;
        for (int j=31; ~j; j--) {
            if ((u>>j)&1) {
                if (x[j]) u^=x[j], k^=y[j];
                else {
                    x[j]=u, y[j]=k; break;
                }
            }
        }
        if (!u) ins(tr[rt], k);
    }
}
void build(int l, int r, int rt) {
    if (l==r) {
        int cnt; uint tmp;
        scanf("%d", &cnt);
        for (int i=0; i<cnt; i++) {
            scanf("%u", &tmp); ins(tr[rt], tmp);
        }
    } else {
        build(l, mid, ls);
        build(mid+1, r, rs);
        merge(rt, ls, rs);
    }
}
bool check(int rt, uint x) {
    for (int i=31; ~i; i--) {
        if ((x>>i)&1) {
            if (tr[rt][i]) x^=tr[rt][i];
            else return false;
        }
    }
    return true;
}
bool query(int l, int r, int L, int R, int rt, uint x) {
    if (L<=l && r<=R) return check(rt, x);
    bool ans=true;
    if (L<=mid) ans=ans && query(l, mid, L, R, ls, x);
    if (mid<R)  ans=ans && query(mid+1, r, L, R, rs, x);
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    for (int l, r; m--; ) {
        uint tmp;
        scanf("%d%d%u", &l, &r, &tmp);
        printf("%s\n", query(1, n, l, r, 1, tmp) ? "YES" : "NO");
    }
    return 0;
}