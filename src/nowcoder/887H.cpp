#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
ll A, B, C;
ll dp[32][2][2][2][2];
ll dfs(int pos, bool upA, bool upB, bool upAnd, bool upXor) {
    if (pos<0) return 1;
    ll &ans=dp[pos][upA][upB][upAnd][upXor];
    if (~ans) return ans;
    ans=0;
    int a=1, b=1, c1=1, c2=0;
    if (upA) a=(A>>pos)&1;
    if (upB) b=(B>>pos)&1;
    if (upAnd) c1=(C>>pos)&1;
    if (upXor) c2=(C>>pos)&1;
    for (int i=0; i<=a; i++) {
        for (int j=0; j<=b; j++) {
            if ((i&j)>c1) continue;
            if ((i^j)<c2) continue;
            ans+=dfs(pos-1, upA&&i==a, upB&&j==b, upAnd&&(i&j)==c1, upXor&&(i^j)==c2);
        }
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        memset(dp, -1, sizeof(dp));
        ll ans=dfs(30, 1, 1, 1, 1);
        ans-=max(0LL, A-C+1);
        ans-=max(0LL, B-C+1);
        printf("%lld\n", A*B-ans);
    }
    return 0;
}