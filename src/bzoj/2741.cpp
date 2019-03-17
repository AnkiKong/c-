#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=12010;
struct node {
    int sz, s[2];
}tr[maxn<<7];
int root[maxn];
int Tcnt;
void ins(int& x, ll val, int loc) {
    tr[++Tcnt] = tr[x]; x = Tcnt; tr[x].sz++;
    if (loc<0) return;
    if (val&(1LL<<loc)) ins(tr[x].s[1], val, loc-1);
    else ins(tr[x].s[0], val, loc - 1);
}
ll query(int ss, int bs, int val, int loc) {
    if (loc < 0) return 0;
    int d = (val>>loc)&1;
    if (tr[tr[bs].s[d^1]].sz - tr[tr[ss].s[d^1]].sz) 
        return query(tr[bs].s[d^1], tr[ss].s[d^1], val, loc-1)|(1LL<<loc);
    else
        return query(tr[bs].s[d], tr[ss].s[d], val, loc-1);
}
int sqrtn[maxn];
int da[maxn];
int ans[maxn][110];
int L[110];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    ins(root[0], 0, 30);
    for (int i = 1; i <= n; i++) {
        scanf("%d", da+i);
        da[i] ^= da[i-1];
        sqrtn[i] = sqrt(i);
        ins(root[i]=root[i-1], da[i], 30);
    }
    int bls = sqrtn[n], blc = n / bls + (n % bls != 0);
    for (int i = 1, l, r; i <= n; i++) {
        for (int j = 1; j <= blc; j++) {
            l = bls * (j-1), r = i;
            if (l > r) continue;
            ans[r][j] = query(root[l], root[r], da[r], 30);
            ans[r][j] = max(ans[r][j], ans[r-1][j]);
            L[j] = l + 1;
        }
    }
    L[blc+1] = n;
    int anss = 0, a, b, l, r;
    while (m--) {
        scanf("%d%d", &a, &b);
        l = (1LL * a + anss) % n + 1;
        r = (1LL * b + anss) % n + 1;
        if (l > r) swap(l, r);
        int lb = (l-1) / bls + 1;
        anss = ans[r][lb+1];
        int R = min(r, L[lb+1]);
        for (int i = l - 1; i <= R; i++) {
            anss = max(1LL * anss, query(root[i], root[r], da[i-1], 30));
        }
        printf("%d\n", anss);
    }
    
    
    return 0;
}