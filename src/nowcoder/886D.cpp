#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2000;
int da[2000];
multiset<int> v;
int n, k;
bool vis[maxn];
int check(int mid) {
    int rs=mid, use=0;
    memset(vis, 0, sizeof(bool)*n+10);
    for (int i=0; i<k; i++) {
        for (int i=0; i<n; i++) {
            if (!vis[i] && da[i]<=rs) {
                rs-=da[i]; use++; vis[i]=1;
            }
        }
        rs=mid;
    }
    return use==n;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &n, &k);
        int l=0, r=0;
        for (int i=0; i<n; i++) {
            scanf("%d", da+i);
            l=max(l, da[i]);
            r+=da[i];
        }
        sort(da, da+n, greater<int>());
        // cout << da[0] << endl;
        l=max(l, r/k);
        for (int i=l; ; i++) {
            if (check(i)) {
                printf("Case #%d: %d\n",TT, i);
                break;
            }
        }
    }
    return 0;
}