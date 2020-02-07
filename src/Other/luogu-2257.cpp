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
const int maxn=1e7+100;
int mu[maxn], p[maxn], pCnt, g[maxn];
bool inp[maxn];
void init() {
    mu[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) p[pCnt++]=i, mu[i]=-1;
        for (int j=0; j<pCnt && i*p[j]<maxn; j++) {
            inp[i*p[j]]=1;
            if (i%p[j]==0) {
                mu[i*p[j]]=0;
                // g[i*p[j]]=mu[i];
                break;
            }
            mu[i*p[j]]=-mu[i];
            // g[i*p[j]]=mu[i]-g[i];
        }
    }
    for (int i=0, t; i<pCnt; i++) {
        t=p[i];
        for (int j=t, d=1; j<maxn; j+=t, d++) {
            g[j]+=mu[d];
        }
    }
    for (int i=1; i<maxn; i++) g[i]+=g[i-1];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ll n, m; scanf("%lld%lld", &n, &m);
        if (n>m) swap(n, m);
        ll ans=0; int nxt;
        for (int i=1; i<=n; i=nxt+1) {
            nxt=min(n/(n/i), m/(m/i));
            ans+=(m/i)*(n/i)*(g[nxt]-g[i-1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}