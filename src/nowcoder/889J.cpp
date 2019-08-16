#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=300000+100;
ll poi[maxn<<3];
ll sum[maxn<<3];
ll lc[maxn][2];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS; 
    int n; cin >> n;
    ll l, r;
    int tot=1;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        l<<=1, r<<=1;
        lc[i][0]=l, lc[i][1]=r;
        poi[tot++]=l, poi[tot++]=r, poi[tot++]=(l+r)>>1;
    }
    sort(poi+1, poi+tot);
    int cnt=unique(poi+1, poi+tot)-poi-1;
    for (int i=0; i<n; i++) {
        int l=lower_bound(poi+1, poi+cnt+1, lc[i][0])-poi;
        int r=lower_bound(poi+1, poi+cnt+1, lc[i][1])-poi;
        int m=lower_bound(poi+1, poi+cnt+1, (lc[i][0]+lc[i][1])>>1)-poi;
        sum[l+1]++; sum[m+1]-=2; sum[r+1]++;
    }
    ll ans=0, nw=0;
    for (int i=1; i<=cnt; i++) {
        sum[i]+=sum[i-1];
        nw+=sum[i]*(poi[i]-poi[i-1]);
        ans=max(ans, nw);
    }
    cout << ans << endl;
    return 0;
}