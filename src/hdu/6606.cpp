#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+100;
int mx[maxn<<2];
void build(int l, int r, int rt) {
    mx[rt]=-inf;
    if (l==r) return;
    build(l, mid, ls); build (mid+1, r, rs);
}

int query(int l, int r, int L, int R, int rt) {
    if (L<=l && r<=R) return mx[rt];
    int ans=-inf;
    if (L<=mid) ans=max(ans, query(l, mid, L, R, ls));
    if (mid<R) ans=max(ans, query(mid+1, r, L, R, rs));
    return ans;
}
void update(int l, int r, int lc, int val, int rt) {
    if (l==r) {
        mx[rt]=val;
    } else {
        if (lc<=mid) update(l, mid, lc, val, ls);
        else update(mid+1, r, lc, val, rs);
        mx[rt]=max(mx[ls], mx[rs]);
    }
}
#undef mid
ll pre1[maxn], pre2[maxn], da[maxn];
int ran[maxn];
int cnt, n, k;
ll ans;
int dp[maxn];
bool check(ll mid) {
    build(0, cnt+1, 1);
    update(0, cnt+1, ran[0], 0, 1);
    for (int i=1, tp, lc; i<=n; i++) {
        lc=lower_bound(pre2, pre2+1+cnt, pre1[i]-mid)-pre2;
        // assert(lc>0);
        tp=query(0, cnt+1, lc, cnt+1, 1);
        update(0, cnt+1, ran[i], tp+1, 1);
    }
    if (query(0, cnt+1, 0, n, 1)>=k) {
        ans=min(ans, mid);
        return true;
    }
    return false;
}
int num[maxn];
void init(int n) {
    for (int i=0; i<=n; i++) {
        pre1[i]=pre2[i]=da[i]=0;    
    }
    ans=INF;
    memset(num, 0, sizeof(num));
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (; t--; ) {
        scanf("%d%d", &n, &k);
        init(n);
        for (int i=1; i<=n; i++) {
            scanf("%lld", da+i);
            pre1[i]=pre2[i]=pre1[i-1]+da[i];
        }
        pre2[0]=0;
        sort(pre2, pre2+1+n);   
        // cnt=unique(pre2+1, pre2+2+n)-pre2-1;
        cnt = n;
        for (int i=0; i<=n; i++) {
            int tp = lower_bound(pre2, pre2+1+cnt, pre1[i])-pre2;
            ran[i]=tp+num[tp];
            num[tp]++;
        } 
        ll l=-1e15, r=1e15, mid;
        while (l<=r) {
            mid=(l+r)>>1;
            if (check(mid)) {
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}