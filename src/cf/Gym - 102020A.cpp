#include<bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif // LOCAL
#define pii pair<double, double>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4+100;
const double PI = acos(-1);
const ll mod = 1e9+7;
ll dp[maxn][10];
void init() {
    memset(dp, -1, sizeof(dp));
}
char str[1000];
int lit[1000], len;
int n, m, k;
int to[][3] = {{4,6,},{6,8,},{7,9,},{4,8,},{3,9,0},{},{1,7,0},{2,6,},{1,3,},{2,4,}};
ll dfs(int x, int level, int pos) {
    if (pos >= len) return 0;
    if (level >= n) return 1;
    // if (dp[level][x] != -1) return dp[level][x];
    ll ans = 0;
    int ccnt = (x == 4 || x == 6) ? 3 : 2;
    for (int i = 0; i < ccnt; i++) {
        int tt = to[x][i];
        if (tt == lit[pos]) {
            ans+=dfs(tt, level+1, pos+1);
        } else {
            if (dp[level+1][tt] != -1) ans += dp[level+1][tt];
            else ans+=dfs(tt, level+1, 0);
        }
        ans %= mod;
    }
    return dp[level][x] = ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    init();
    scanf("%d%d%d", &n, &m, &k);
    if (m) {
        scanf("%s", str);
        for (int i = 0; str[i]; len++, i++)
            lit[i] = str[i] - '0';
    } else {
        lit[0] = -1;
        len = 100000;
    }
    if (k == 5) {
        printf("0");
        return 0;
    }
    ll ans = dfs(k, 0, 0);
    printf("%lld", ans);
    return 0;
}