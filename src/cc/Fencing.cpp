#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
#define pii pair<int,int>
int n, m, k;
bool check(int x, int y) {
    return x>0 && y>0 && x<=n && y<=m;
}
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        set<pii >bl;
        scanf("%d%d%d", &n, &m, &k);
        for (int i=0, a, b; i<k; i++) {
            scanf("%d%d", &a, &b);
            bl.insert(pii(a, b));
        }
        int ans=0;
        for (pii a:bl) {
            int x=a.first, y=a.second, nx, ny;
            for (int i=0; i<4; i++) {
                nx=x+dx[i];
                ny=y+dy[i];
                if (check(nx, ny)) {
                    ans+=bl.count(pii(nx, ny)) ? 0 : 1;
                } else {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}