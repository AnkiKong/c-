#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
ll v[maxn], m[maxn];
vector<int> ve[maxn];
vector<int> leaf;
ll ans[maxn];
void dfs(int x, int fa, ll sum) {
    bool hasSon=0;
    sum=__gcd(sum, v[x]);
    for (auto a:ve[x]) {
        if (a==fa) continue;
        hasSon=1;
        dfs(a, x, sum);
    }
    if (!hasSon) {
        leaf.push_back(x);
        ans[x]=m[x]-__gcd(m[x], sum);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n; scanf("%d", &n);
        for (int i=0; i<=n; i++) ve[i].clear();
        leaf.clear();
        for (int i=1, a, b; i<n; i++) {
            scanf("%d%d", &a, &b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        for (int i=1; i<=n; i++) scanf("%lld", v+i);
        for (int i=1; i<=n; i++) scanf("%lld", m+i);
        dfs(1, -1, 0);
        sort(leaf.begin(), leaf.end());
        for (auto a:leaf) {
            printf("%lld ", ans[a]);
        }
        puts("");
    }    
    return 0;
}