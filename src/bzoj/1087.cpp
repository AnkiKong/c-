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
// const int maxn=;
ll dp[10][100][512];
int cnt[512];
bool can[512][512], rcan[512];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, kk; scanf("%d%d", &n, &kk);
    int all = 1<<n;
    for (int i = 0, s; i < all; i++) {
        if (i & (i>>1)) continue;
        s = 0;
        for (int j = i; j; j>>=1) s += j&1;
        cnt[i] = s; rcan[i] = 1;
    }
    for (int i = 0; i < all; i++) {
        if (!rcan[i]) continue;
        for (int j = 0; j < all; j++) {
            if (!rcan[j]) continue;
            if (i&j || (i>>1)&j || i&(j>>1)) continue;
            can[i][j] = 1;
        }
    }
    for (int i = 0; i < all; i++) 
        if (rcan[i]) dp[1][cnt[i]][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < all; j++) {
            if (!rcan[j]) continue;
            for (int k = 0; k < all; k++) {
                if (!rcan[k] || !can[j][k]) continue;
                for (int p = cnt[j]; p + cnt[k] <= kk; p++) {
                    dp[i][p+cnt[k]][k] += dp[i-1][p][j];
                } 
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < all; i++) ans += dp[n][kk][i];
    printf(lld, ans);
    return 0;
}