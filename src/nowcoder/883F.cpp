#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=550;
int a1[N<<1], a2[N<<1];
int da[N][N];
int mx[N], mn[N];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int n, m; t--; ) {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                scanf("%d", da[i]+j);
        int ans=0;
        for (int i=1; i<=n; i++) {
            for (int j=i; j; j--) {
                int h1=N, h2=N, t1=N-1, t2=N-1;
                int L=1;
                for (int k=1; k<=n; k++) {
                    if (i==j) mx[k]=mn[k]=da[i][k];
                    while (h1<=t1 && mx[k]>=mx[a1[t1]]) t1--;
                    while (h2<=t2 && mn[k]<=mn[a2[t2]]) t2--;
                    a1[++t1]=a2[++t2]=k;
                    while (mx[a1[h1]]-mn[a2[h2]]>m && L<=k) {
                        L++;
                        while (h1<=t1 && a1[h1]<L) h1++;
                        while (h2<=t2 && a2[h2]<L) h2++;
                    }
                    ans=max(ans, (i-j+1)*(k-L+1));
                }
                for (int k=1; k<=n; k++) {
                    mx[k]=max(mx[k], da[j-1][k]);
                    mn[k]=min(mn[k], da[j-1][k]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}