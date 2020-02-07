#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
#define pii pair<int,int>
vector<int> da, ds;
map<int, int> cnt;
map<int, 
vector<int> >loc;
ll lcm(ll a, ll b) {
    return a/__gcd(a, b)*b;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // cf=1154
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i=1, a; i<=n; i++) {
        cin >> a;
        loc[a].push_back(i);
        ds.push_back(a);
        if (cnt.find(a)==cnt.end()) {
            da.push_back(a);
        }
        cnt[a]++;
    }
    sort(da.begin(), da.end());
    if (da.size()==1) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    ll mn=lcm(da[0], da[1]), l, r;
    l=loc[da[0]][0], r=loc[da[1]][0];
    int len=da.size();
    for (int i=0; i<len; i++) {
        if (da[i]>=mn) break;
        if (cnt[da[i]]>1) {
            l=loc[da[i]][0], r=loc[da[i]][1];
            mn=da[i];
            break;
        }
        for (int j=i+1; j<len; j++) {
            if (da[j]>=mn) break;
            if (cnt[da[j]]>1) {
                mn=da[j]; l=loc[da[j]][0], r=loc[da[j]][1];
                break;
            }
            ll lm = lcm(da[i], da[j]);
            if (lm<mn) {
                mn=lm; l=loc[da[i]][0], r=loc[da[j]][0];
            }
        }
    }
    if (l>r) swap(l, r);
    cout << l << " " << r;
    return 0;
}