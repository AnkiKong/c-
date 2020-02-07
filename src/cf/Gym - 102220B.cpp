#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
vector<int> da[maxn];
#define pii pair<ll,ll>
priority_queue<pii, vector<pii>, greater<pii> > q;
int Cnt[maxn];
void init(int n) {
    for (int i=0; i<=n; i++) da[i].clear();
    for (; q.size(); q.pop());
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int t; cin >> t;
    for (int n, m; t--; ) {
        cin >> n >> m;
        init(m);
        for (int i=1; i<=m; i++) cin >> Cnt[i];
        for (int i=1, a, b; i<=n; i++) {
            cin >> a >> b;
            da[b].push_back(a);
        }
        for (int i=1; i<=m; i++) {
            auto &ar=da[i];
            int nC=Cnt[i];
            sort(ar.begin(), ar.end(), greater<int>());
            ll sum=0;
            for (int i=0; i<(int)ar.size(); i++) {
                sum+=ar[i];
                if (i+1>=nC) q.push(pii(i+1, sum)), sum=0;
            }
        }
        ll ans1=0, ans2=1;
        ll tmp=0;
        ll a1, a2, gcd;
        for (ll i=1; q.size(); i++) {
            while (q.size() && q.top().first<=i) {
                tmp+=q.top().second; q.pop();
            }
            gcd=__gcd(i, tmp);
            a1=tmp/gcd; a2=i/gcd;
            if (ans1*a2<a1*ans2) {
                ans1=a1; ans2=a2;
            }
        }
        cout << ans1 << "/" << ans2 << "\n";
    }
    return 0;
}