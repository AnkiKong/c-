#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=26;
char dp[1<<maxn];
int v[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    for (int i=0, a, b; i<m; i++) {
        scanf("%d%d", &a, &b);
        v[a]|=1<<b;
        v[b]|=1<<a;
    }
    for (int i=0; i<n; i++) v[i]|=1<<i, v[i]=~v[i];
    int last=0, ans=0;
    for (int i=1; i<(1<<n); i++) {
        last+=!((i>>last)&1);
        dp[i]=max(dp[i^(1<<last)], char(dp[i&v[last]]+1));
        ans+=dp[i];
    }
    printf("%d\n", ans);
    return 0;
}