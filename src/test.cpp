#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e7+10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll da[N];
ll base10[20];
int cnt;
void init() {
    base10[0]=1;
    for (int i=1; i<20; i++) base10[i]=base10[i-1]*10;
}
inline int cal(ll a) {
    int ans=0;
    while (a) ans++, a/=10;
    return ans;
}
ll merge(ll a, ll b) {
    return a*base10[cal(b)]+b;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    for (ll i=1; i<=1e5; i++) {
        for (ll j=i+1; j<=1e5; j++) {
            // if (i==j) continue;
            if (j*j%i!=0) continue;
            if (cal(i)+cal(j)+cal(j*j/i)>15) break;
            ll nw=merge(i, j);
            ll last=j, newN;
            for (; ; ) {
                if (j*last%i!=0) break;
                newN=j*last/i;
                if (cal(nw)+cal(newN)>15) break;
                if (merge(nw, newN)>1e15) break;
                da[cnt++]=nw=merge(nw, newN);
                last=newN;
            }
        }
        // if (cnt==1413619) break;
        cout << cnt << endl;
    }
    sort(da, da+cnt);
    int t; cin >> t;
    for (ll l, r, T=1; t--; T++) {
        cin >> l >> r;
        cout << "Case #" << T << ": ";
        cout << (upper_bound(da, da+cnt, r)-upper_bound(da, da+cnt, l-1)) << "\n";
    }
    return 0;
}
