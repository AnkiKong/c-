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
    for (int i = 1, sq = sqrtn[n]; i <= n; i++) {
        for (int j = 1; j <= sq; j++) {
            
        }
    }
    
    
    return 0;
}