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
const int maxn=1e5+100;
const int maxm=1e9+10;
bool inp[maxn];
int p[maxn], pCnt;
void getP() {
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) p[pCnt++]=i;
        for (int j=0; j<pCnt && i*p[j]<maxn; j++) {
            inp[i*p[j]]=1;
            if (i%p[j]==0) break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    getP();
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n, m; scanf("%d", &n);
        m=n; ll ans1=1, ans2=n;
        for (int i=0; p[i]*p[i]<=m && i<pCnt; i++) {
            if (m%p[i]) continue;
            ll cnt=1; ll tmp=p[i];
            while (m%p[i]==0) {
                cnt++; m/=p[i]; tmp*=p[i];
            }
            ans2*=cnt;
            ll a=(tmp-1)/(p[i]-1), b=1+tmp, c=1+p[i]; 
            if (a%c==0) ans1*=a/c*b;
            else ans1*=b/c*a;
        }
        if (m>1) {
            ans2*=2; ans1*=(1LL*m*m+1);
        }
        printf("%lld\n", ans1-ans2);
    }
    return 0;
}