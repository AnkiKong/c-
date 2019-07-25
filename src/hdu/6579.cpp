#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5e5+100;
int da[maxn][31], loc[maxn][31], p[31];
void ins(int* da, int* loc, int val, int lc) {
    for (int i=30; ~i; i--) {
        if ((val>>i)&1) {
            if (!da[i]) {
                da[i]=val; loc[i]=lc;
                return;
            } else {
                if (loc[i]<lc) {
                    swap(lc, loc[i]); swap(val, da[i]);
                }
                val^=da[i];
            }
        }
    }
}
int query(int* da, int* loc, int lc) {
    int ans=0;
    for (int i=30; ~i; i--) {
        if (loc[i]>=lc && (ans^da[i])>ans) ans^=da[i];
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int n, m; t--; ) {
        scanf("%d%d", &n, &m);
        for (int i=1, a; i<=n; i++) {
            scanf("%d", &a);
            memcpy(da[i], da[i-1], sizeof(da[i]));
            memcpy(loc[i], loc[i-1], sizeof(loc[i]));
            ins(da[i], loc[i], a, i);
        }
        int last=0;
        for (int l, r, op, a; m--; ) {
            scanf("%d", &op);
            if (op==1) {
                scanf("%d", &a); n++;
                a^=last;
                memcpy(da[n], da[n-1], sizeof(da[n]));
                memcpy(loc[n], loc[n-1], sizeof(loc[n]));
                ins(da[n], loc[n], a, n);
            } else {
                scanf("%d%d", &l, &r);
                l=(l^last)%n+1, r=(r^last)%n+1;
                if (l>r) swap(l, r);
                printf("%d\n", last=query(da[r], loc[r], l));
            }
        }
    }
    return 0;
}