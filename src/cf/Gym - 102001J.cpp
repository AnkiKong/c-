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
const int maxn=20;
int dp[maxn][1<<17];
int sz[maxn];
string s[maxn];
vector<string> ss[maxn];
void dfs(auto nw, auto ed, string s, vector<string>& con) {
    if (nw==ed) con.push_back(s);
    else {
        dfs(nw+1, ed, s, con);
        dfs(nw+1, ed, s+*nw, con);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; cin>>n;
    memset(dp, -0x3f, sizeof(dp));
    string s;
    for (int i=1; i<=n; i++) {
        cin>>s;
        dfs(s.begin(), s.end(), "", ss[i]);
        sz[i]=ss[i].size();
        sort(ss[i].begin(), ss[i].end());
    }
    for (int i=1; i<sz[1]; i++) {
        dp[1][i]=max(dp[1][i-1], (int)ss[1][i].size());
    }
    for (int i=2; i<=n; i++) {
        int k=0;
        for (int j=1; j<sz[i]; j++) {
            while (k<sz[i-1] && ss[i-1][k]<ss[i][j]) k++;
            dp[i][j]=max(dp[i][j-1], dp[i-1][k-1]+(int)ss[i][j].size());
        }
    }
    cout << (dp[n][sz[n]-1]<0 ? -1 : dp[n][sz[n]-1])<< endl;
    return 0;
}