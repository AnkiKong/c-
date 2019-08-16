#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3100;
int mp[maxn][maxn];
char str[maxn];
int stk[maxn], top;
int pre[maxn];
int up[maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%s", str+1);
        for (int j=1; j<=m; j++) {
            mp[i][j]=str[j]=='1';
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        top=0;
        for (int j=1; j<=m+1; j++) {
            up[j]=(mp[i][j]?up[j]+1:0);
            pre[j]=pre[j-1]+mp[i+1][j];
            while (top>0 && up[stk[top]]>up[j]) {
                if (pre[j-1]-pre[stk[top-1]]<j-stk[top-1]-1 && up[stk[top-1]]<up[stk[top]]) ans++;
                top--;
            }
            stk[++top]=j;
        }
    }
    printf("%d\n", ans);
    return 0;
}