#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1700;
int a[maxn][maxn];
int n, m;
int var, equ;
int ans[1700];
vector<int> free_x;
int g() {
    int mxr, col, k;
    for (k=0, col=0; k<equ && col<equ; k++, col++) {
        mxr=k;
        for (int i=k+1; i<equ; i++) {
            if (abs(a[mxr][col])<abs(a[i][col])) mxr=i;
        }
        if (a[mxr][col]==0) {
            free_x.push_back(col), k--;
            continue;
        }
        if (mxr!=k) {
            for (int j=col; j<var+1; j++) {
                swap(a[mxr][j], a[k][j]);
            }
        }
        for (int i=k+1; i<equ; i++) {
            if (a[i][col]!=0) {
                for (int j=col; j<var+1; j++) {
                    a[i][j]^=a[k][j];
                }
            }
        }
    }
    for (int i=k; i<equ; i++) {
        if (a[i][col]!=0) return -1;
    }
    if (k<var) return var-k;
    for (int i=var-1; i>=0; i--) {
        ans[i]=a[i][var];
        for (int j=i+1; j<var; j++) {
            ans[i]^=(a[i][j]&&ans[j]);
        }
    }
    return 0;
}
void init() {
    equ=m*n, var=m*n;
    free_x.clear();
    // for (int i=0; i<=equ; i++) a[i].reset();
    memset(ans, 0, sizeof(ans));
    memset(a, 0, sizeof(a));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int t=i*m+j;
            a[t][t]=1;
            if (i>0) a[(i-1)*m+j][t]=1;
            if (i<n-1) a[(i+1)*m+j][t]=1;
            if (j>0) a[i*m+j-1][t]=1;
            if (j<m-1) a[i*m+j+1][t]=1;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int t; cin >>t;
    for (; t--; ) {
        cin >> n >> m;
        init();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                a[i*m+j][m*n]=0;
            }
        }
        int t=g();
        if (t==0) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    cout << 0 << " \n"[j==m-1];
                }
            }
        } else {
            for (int aa:free_x) {
                ans[aa]=1;
            }
            for (int j=var-t-1; j>=0; j--) {
                int idx;
                for (idx=j; idx<var; idx++) {
                    if (a[j][idx]) break;
                }
                ans[idx]=a[j][var];
                for (int l=idx+1; l<var; l++) {
                    if (a[j][l])
                        ans[idx]^=ans[l];
                }
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    cout << ans[i*m+j] << " \n"[j==m-1];
                }
            }
        }
    }
    return 0;
}