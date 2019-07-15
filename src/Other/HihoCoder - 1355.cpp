#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2000;
char str[maxn];
vector<int> s;
ll r=1, c=0;
ll n, m;
void work() {
    for (int a:s) {
        if (c==m) r++, c=0;
        c++;
        if (c+a>m) r++, c=0;
        c+=a;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);
    while (~scanf("%s", str)) {
        s.push_back(strlen(str));
    }
    #define pii pair<int,ll>
    map<int,pii> rs;
    c=-1;
    for (int i=1; i<=n; i++) {
        work();
        if (rs.count(c)) {
            ll a=(n-i)/(i-rs[c].first);
            ll b=(n-i)%(i-rs[c].first);
            r+=a*(r-rs[c].second);
            for (int j=1; j<=b; j++) {
                work();
            }
            break;
        }
        rs[c]=pii(i, r);
    }
    printf("%lld %lld", r, c);
    return 0;
}