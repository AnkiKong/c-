#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=4e5;
int dp[maxn];
vector<int> v[maxn];
int st[maxn];
int sum;
void dfs(int nx) {
    if (!v[nx].size()) {
        sum++, dp[nx]=1; return;
    }
    int minn=0, mx=inf;
    for (auto a:v[nx]) {
        dfs(a);
        minn+=dp[a];
        mx=min(mx, dp[a]);
    }
    if (st[nx]) {
        dp[nx]=mx;
    } else {
        dp[nx]=minn;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", st+i);
    }
    for (int i=2, a; i<=n; i++) {
        scanf("%d", &a);
        v[a].push_back(i);
    }
    dfs(1);
    printf("%d", sum-dp[1]+1);
    return 0;
}