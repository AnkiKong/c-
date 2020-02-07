#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1)|1
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
int a[maxn];
int root[maxn<<6], mx;
struct node {
    int l, r;
    ll sum;
}tr[maxn<<6];
int Tcnt;
void ins(int num, int l, int r, int& x) {
    tr[++Tcnt]=tr[x]; x=Tcnt; tr[x].sum+=num;
    if (l==r) return ;
    if (num<=mid) ins(num, l, mid, tr[x].l);
    else ins(num, mid+1, r, tr[x].r);
}
ll query(int ss, int bs, int l, int r, int val) {
    if (val<l) return 0;
    if (r<=val) return tr[bs].sum-tr[ss].sum;
    ll ans=tr[tr[bs].l].sum-tr[tr[ss].l].sum;
    if (val<=mid) return query(tr[ss].l, tr[bs].l, l, mid, val);
    else return ans + query(tr[ss].r, tr[bs].r, mid+1, r, val);
}
ll solve(int l, int r) {
    ll nxt=0;
    for (ll i=1; ; i=nxt+1) {
        nxt=query(root[l-1], root[r], 1, mx, i);
        if (nxt<i) return i;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i]; mx=max(mx, a[i]);
    }
    for (int i=1; i<=n; i++) {
        ins(a[i], 1, mx, root[i]=root[i-1]);
    }
    int Q; cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << "\n";
    }
    
    return 0;
}