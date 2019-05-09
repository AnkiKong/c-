#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
ll sum[maxn][2];
vector<int> v[maxn];
int n, X;
void dfs(int x, int fa) {
    for (auto a:v[x]) {
        if (a==fa) continue;
        dfs(a, x);
        sum[x][0]+=max(sum[a][0], sum[a][1]);
    }
    sum[x][1]=-X;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &n, &X);
        for (int i=0; i<=n; i++) v[i].clear();
        for (int i=1; i<=n; i++) scanf("%lld", sum[i]);
        for (int i=1, a, b; i<n; i++) {
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1, -1);
        ll ans=max(sum[1][0], sum[1][1]);
        if (ans<-X) ans=-X;
        printf("%lld\n", ans);
    }
    return 0;
}