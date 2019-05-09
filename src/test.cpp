#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1010;
int da[maxn];
int dp[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> da[i];
    for (int i=1; i<=n; i++) dp[i][1]=da[i];
    for (int i=2; i<n; i++) {
        for (int j=1; j+i<=n; j++) {
            dp[j][i]=min(dp[])
        }
    }
    return 0;
}