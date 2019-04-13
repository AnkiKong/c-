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
const int maxn=5e6+100;
bool inp[maxn];
int p[448617], mu[maxn], pCnt;
void init() {
    mu[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) p[pCnt++]=i, mu[i]=-1;
        for (int j=0, t; j<pCnt && (t=p[j]*i)<maxn; j++) {
            inp[t]=1;
            if (i%p[j]==0) {
                mu[t]=0; break;
            }
            mu[t]=-mu[i];
        }
    }
    for (int i=1; i<maxn; i++) mu[i]+=mu[i-1];
}
unordered_map<ll, int> mp;
int getAns(ll a) {
    if (a<maxn) return mu[a];
    if (mp.find(a)!=mp.end()) return mp[a];
    int ans=1;
    ll r;
    for (ll i=2; i<=a; i=r+1) {
        r=a/(a/i);
        ans-=getAns(a/i)*(r-i+1);
    }
    return mp[a]=ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    ll a, b; scanf("%lld%lld", &a, &b);
    printf("%d\n", getAns(b)-getAns(a-1));
    return 0;
}