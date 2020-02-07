#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e4;
int a[maxn], b[maxn], lis[maxn];
int pre[maxn];
bool vis[maxn];
vector<int> rLis;
int n;
int getLIS() {
    int cnt=0;
    for (int i=1; i<=n; i++) {
        if (vis[i]) continue;
        if (a[i]>lis[cnt]) lis[++cnt]=a[i], pre[a[i]]=lis[cnt-1];
        else {
            int lc=lower_bound(lis, lis+cnt+1, a[i])-lis;
            pre[a[i]]=lis[lc-1];
            lis[lc]=a[i];
        }
    }
    rLis.clear();
    rLis.push_back(lis[cnt]);
    for (int i=pre[lis[cnt]]; i; i=pre[i]) {
        rLis.push_back(i);
    }
    reverse(rLis.begin(), rLis.end());
    return cnt;
}
int ans[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(bool)*(n+10));
        for (int i=1; i<=n; i++) scanf("%d", a+i);
        for (int i=1; i<=n; i++) scanf("%d", b+i);
        int cnt=getLIS();
        ans[n]=cnt;
        for (int i=n, j; i>0; i--) {
            j=b[i]; vis[j]=1;
            if (*lower_bound(rLis.begin(), rLis.end(), a[j])==a[j]) {
                cnt=getLIS();
            }
            ans[i-1]=cnt;
        }
        for (int i=1; i<=n; i++) printf("%d%c", ans[i], " \n"[i==n]);
    }
    return 0;
}