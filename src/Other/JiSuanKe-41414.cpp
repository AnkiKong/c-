#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5;
__int128 dp[30][30][30];

string ans;
int n;
void query(int level, int limit, auto need, auto nw) {
    if (level>n) return;
    for (int i=1; i<=26 && i<=limit+1; i++) {
        int lt=max(i, limit);
        if (need>nw[level][lt]) need-=nw[level][lt];
        else {
            cout << char('A'+i-1);
            query(level+1, lt, need, nw);
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i=1; i<=26; i++) {
        for (int j=1; j<=26; j++) dp[i][i][j]=1;
        for (int j=i-1; j>0; j--) {
            for (int k=1; k<=j; k++) {
                dp[i][j][k]=dp[i][j+1][k]*k+dp[i][j+1][k+1];
            }
        }
    }
    // for (int i=1; i<=26; i++) {
    //     for (int j=1; j<=i; j++) {
    //         cout << dp[26][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    IOS;
    int t; cin >> t;
    string kk;
    __int128 k;
    for (int T=1; t--; T++) {
        cin >> n >> kk;
        k=0;
        for (char c:kk) {
            k=k*10+(c-'0');
        }
        
        cout << "Case #" << T <<": ";
        query(1, 1, k, dp[n]);
        cout << "\n";
    }
    return 0;
}