#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
int ans[2000][2000];
void dfs(int x, int y, int val, int len) {
    if (len==1) {
        ans[x][y]=val;
    } else {
        int nw=len>>1;
        dfs(x, y, val, nw);
        dfs(x+nw, y, val, nw);
        dfs(x, y+nw, val, nw);
        dfs(x+nw, y+nw, -val, nw);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    dfs(1, 1, 1, n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}