#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
#define pii pair<int, int>
ll a[maxn], b[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<n; i++) cin >> b[i];
    int m, l, r; cin >> m;
    string s;
    for (; m--; ) {
        cin >> s >> l >> r;
        if (s[0]=='+') {
            a[l]+=r;
            for (int i=l+1; i<=n; i++) {
                if (a[i]<a[i-1]+b[i-1]) {
                    a[i]=a[i-1]+b[i-1];
                } else {
                    break;
                }
            }
        } else {
            ll ans=0;
            for (int i=l; i<=r; i++) {
                ans += a[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}