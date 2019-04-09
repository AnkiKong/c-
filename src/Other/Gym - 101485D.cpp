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
const int maxn=1e6+100;
ll dp[maxn];
ll r, p;
ll dfs(int x) {
    if (dp[x]) return dp[x];
    if (x<=1) return 0;
    ll ans=x*p;
    for (int i=2; i<x; i=(x-1)/((x-1)/i)+1) ans=min(ans, dfs((x-1)/i+1)+p*i);
    return dp[x]=ans+r-p;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d%lld%lld", &n, &r, &p);
    printf("%lld\n", dfs(n));
    return 0;
}