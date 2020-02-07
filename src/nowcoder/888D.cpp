#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
int n, m, h;
void mx(int& a, int b) {
    a=max(a, b);
}
struct node {
    int a[maxn];
    node() {
        memset(a, -0x3f3f, sizeof(a));
    }
    int gId(int x, int y, int z) {
        return x*h*m+y*h+z;
    }
    int lowbit(int x) {
        return -x&x;
    }
    void update(int x, int y, int z, int val) {
        for (int i=x; i<=n; i+=lowbit(i)) 
            for (int j=y; j<=m; j+=lowbit(j))
                for (int k=z; k<=h; k+=lowbit(k))
                    mx(a[gId(i, j, k)], val);
    }
    int query(int x, int y, int z) {
        int ans=-inf;
        for (int i=x; i; i-=lowbit(i))
            for (int j=y; j; j-=lowbit(j))
                for (int k=z; k; k-=lowbit(k))
                    ans=max(ans, a[gId(i, j, k)]);
        return ans;
    }
}T[8];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int q; cin >> n >> m >> h >> q;
    for (int op, x, y, z; q--; ) {
        cin >> op >> x >> y >> z;
        if (op==1) {
            T[0].update(x, y, z, x+y+z);
            T[1].update(x, y, h-z+1, x+y-z);
            T[2].update(x, m-y+1, z, x-y+z);
            T[3].update(n-x+1, y, z, -x+y+z);
            T[4].update(x, m-y+1, h-z+1, x-y-z);
            T[5].update(n-x+1, y, h-z+1, -x+y-z);
            T[6].update(n-x+1, m-y+1, z, -x-y+z);
            T[7].update(n-x+1, m-y+1, h-z+1, -x-y-z);
        } else {
            int ans=inf;
            ans=min(ans, x+y+z-T[0].query(x, y, z));
            ans=min(ans, x+y-z-T[1].query(x, y, h-z+1));
            ans=min(ans, x-y+z-T[2].query(x, m-y+1, z));
            ans=min(ans, -x+y+z-T[3].query(n-x+1, y, z));
            ans=min(ans, x-y-z-T[4].query(x, m-y+1, h-z+1));
            ans=min(ans, -x+y-z-T[5].query(n-x+1, y, h-z+1));
            ans=min(ans, -x-y+z-T[6].query(n-x+1, m-y+1, z));
            ans=min(ans, -x-y-z-T[7].query(n-x+1, m-y+1, h-z+1));
            cout << ans << "\n";
        }
    }
    return 0;
}