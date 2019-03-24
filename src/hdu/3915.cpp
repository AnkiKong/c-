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
const int maxn=110;
int mp[33][maxn];
int n; 
int solve() {
    int free=0;
    for (int row=0, col=0; row<31 && col<n; col++, row++) {
        int max_row=row;
        for (int i = row+1; i<31; i++) {
            if (mp[i][col]>mp[max_row][col]) max_row=i;
        }
        if (mp[max_row][col]==0) {
            free++; row--; continue;
        }
        if (max_row != row) {
            for (int i = 0; i < n; i++) swap(mp[max_row][i], mp[row][i]);
        }
        for (int i = row+1; i<31; i++) {
            if (!mp[i][col]) continue;
            for (int j = col; j < n; j++) {
                mp[i][j] ^= mp[row][j];
            }
        }
    }
    return free;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &n);
        for (int i = 0, a; i < n; i++) {
            scanf("%d", &a);
            for (int j = 0; j < 31; j++, a>>=1) {
                mp[j][i] = a&1;
            }
        }
        ll ans = 1;
        const int mod=1000007;
        for (int i = solve(); i; i--) {
            ans = ans * 2 % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}