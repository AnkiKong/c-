#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
map<ll, int> cnt;
void div(ll a) {
    for (ll i=2; i*i<=a; i++) {
        while (a%i==0) cnt[i]++, a/=i;
    }
    if (a>1) cnt[a]++;
}
ll ans1, ans2;
ll a, b, m, ab;
void dfs(auto nx, ll val) {
    if (nx == cnt.end()) {
        ll x=val+b;
        if (x>=m) {
            ll y=ab/val+a;
            // if (x<=0 || y<=0) return;
            if (ans1==-1) ans1=x, ans2=y;
            else if (x+y<ans1+ans2) {
                ans1=x, ans2=y;
            } else if (x+y==ans1+ans2 && x<ans1) {
                ans1=x, ans2=y;
            }
        }
        return;
    }
    ll v=nx->first, cnts=nx->second; nx++;
    dfs(nx, val);
    for (int i=1; i<=cnts; i++) {
        val*=v;
        dfs(nx, val);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%lld%lld%lld", &a, &b, &m)) {
        ans1=-1;
        cnt.clear();
        div(a); div(b); ab=a*b;
        auto start=cnt.begin();
        dfs(start, 1);
        if (ans1!=-1)
            printf("%lld %lld\n", ans1, ans2);
        else 
            printf("No answer\n");
    }
    return 0;
}