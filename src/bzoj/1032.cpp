#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;
const int maxn=600;
int da[maxn];
int dp[maxn][maxn];
bool vis[maxn][maxn];
int dfs(int l, int r) {
    if (l == r) return 2;
    int& res = dp[l][r];
    if (vis[l][r]) return res;
    vis[l][r] = 1;
    res = inf;
    for (int i = l; i < r; i++) 
        res = min(res, dfs(l, i) + dfs(i+1, r));
    if (da[l] != da[r]) return res;
    int pos1 = l, pos2 = r;
    while (pos1 <= pos2 && da[pos1+1] == da[pos1]) pos1++;
    while (pos2 >= pos1 && da[pos2-1] == da[pos2]) pos2--;
    if (pos1 > pos2) return res = 1;
    int add = 0;
    if (r - l - (pos2 - pos1) < 1) add = 1;
    res = min(res, dfs(pos1+1, pos2-1) + add);
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", da+i);
    printf("%d\n", dfs(1, n));
    return 0;
}