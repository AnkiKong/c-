#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2100;
char str[maxn];
int mp[maxn][maxn];
int sm[maxn][maxn];
inline get(int lx, int ly, int rx, int ry) {
    return sm[rx][ry]-sm[rx][ly-1]-sm[lx-1][ry]+sm[lx-1][ly-1];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int n, k; cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> str;
        for (int j=1; j<=n; j++) {
            mp[i][j]=str[j]=='W';
        }
    }
    int kk=k*k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            sm[i][j]=sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+mp[i][j];
        }
    }
    int mn=0, ii, jj;
    for (int i=1; i+k<=n; i++) {
        for (int j=1; j+k<=n; j++) {
            int _1=get(i, 1, i+k-1, j-1);
            int _4=get(1, j, i-1, j+k-1);
            int _2=get(i+k, j, n, j+k-1);
            int _3=get(i, j+k, i+k-1, n);
            int tp=_1+_2+_3+_4+kk;
            if (tp>mn) {
                mn=tp; ii=i, jj=j;
            }
        }
    }
    int ans=0;
    for (int i=ii; i<ii+k; i++) {
        int ss=0;
        for (int j=1; j<=n; j++) {
            if (j>=jj && j<jj+k) ss+=mp[i][j];
        }
        if (ss==n) ans++;
    }
    for (int i=ii; i<ii+k; i++) {
        int ss=0;
        for (int j=1; j<=n; j++) {
            if (j>=ii && j<ii+k) ss+=mp[j][i];
        }
        if (ss==n) ans++;
    }
    cout << ans;
    return 0;
}