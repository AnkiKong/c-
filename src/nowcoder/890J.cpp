#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef __int128_t LL;
const int inf=0x3f3f3f3f;
const int maxn=6000;

LL *dp1, *dp2;
LL tp1[maxn], tp2[maxn];
#define pii pair<ll,ll>
pii bo[maxn];
LL pre[maxn], aSum[maxn];
LL cal1(int j, int i) {
    return (dp1[i]-aSum[i]+bo[i+1].first*pre[i])-(dp1[j]-aSum[j]+bo[j+1].first*pre[j]);
}
LL cal2(int j, int i) {
    return bo[i+1].first-bo[j+1].first;
}
LL cal3(int i, int j) {
    return dp1[i]+aSum[j]-aSum[i]-bo[i+1].first*(pre[j]-pre[i]);
}
int que[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int n, k;
    cin >> n >> k;
    dp1=tp1; dp2=tp2;
    for (int i=1; i<=n; i++) {
        cin >> bo[i].second >> bo[i].first;
    }
    sort(bo+1, bo+n+1);
    for (int i=1; i<=n; i++) {
        pre[i]=pre[i-1]+bo[i].second;
        aSum[i]=aSum[i-1]+bo[i].first*bo[i].second;
        dp1[i]=aSum[i]-pre[i]*bo[1].first;
    }
    int h, t;
    // dp1=tp2, dp2=tp1;
    for (int i=2; i<=k; i++) {
        h=t=0;
        que[t++]=i-1;
        for (int j=i; j<=n; j++) {
            while (t-h>1 && cal1(que[h], que[h+1])<=pre[j]*cal2(que[h], que[h+1])) h++;
            dp2[j]=cal3(que[h], j);
            while (t-h>1 && cal1(que[t-1], j)*cal2(que[t-2], que[t-1])<=cal1(que[t-2], que[t-1])*cal2(que[t-1], j)) t--;
            que[t++]=j;
        }
        swap(dp1, dp2);
    }
    ll ans=dp1[n];
    cout << ans;
    return 0;
}