#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=6e6+100;
int pri[maxn], mu[maxn], phi[maxn];
ll muS[maxn];
int tot;
bool inp[maxn];
void init() {
    mu[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) pri[tot++]=i, mu[i]=-1;
        for (int j=0; j<tot && 1LL*i*pri[j]<maxn; j++) {
            inp[i*pri[j]]=1;
            if (i%pri[j]==0) {
                mu[i*pri[j]]=0; break;
            } else {
                mu[i*pri[j]]=-mu[i];
            }
        }
    }
    for (int i=1; i<maxn; i++) {
        muS[i]=muS[i-1]+mu[i];
    }
}
ll S1(ll n) {
    if (n<maxn) return muS[n];
    static unordered_map<ll,ll> vis;
    if (vis.count(n)) return vis[n];
    ll res=1;
    for (ll i=2, r, val; i<=n; i=r+1) {
        val=n/i; r=n/val;
        res-=S1(val)*(r-i+1);
    }
    return vis[n]=res;
}
ll S2(ll n) {
    ll res=0;
    for (ll i=1, val, r; i<=n; i=r+1) {
        val=n/i; r=n/val;
        res+=val*val*(S1(r)-S1(i-1));
    }
    return ((res-1)>>1)+1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int t; cin >> t;
    for (ll n; t--; ) {
        cin >> n;
        cout << S2(n) << " " << S1(n) << "\n";
    }
    return 0;
}