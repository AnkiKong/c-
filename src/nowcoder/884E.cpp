#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int N=62;
ll C[N][N], B[N][3], F[N][N];
auto add(auto& a, auto b) {
    a+=b; if (a>=mod) a-=mod;
    return a;
}
void init() {
    C[0][0]=1;
    for (int i=1; i<N; i++) {
        C[i][0]=1;
        for (int j=1; j<=i; j++) {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<=i; j++) {
            add(B[i][j%3], C[i][j]);
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<=i; k++) {
                add(F[i][j], 1LL*C[i][k]*B[j][k%3]%mod);
            }
        }
    }
}
int qpow(ll a, ll b) {
    ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    init();
    int cnt1, cnt2;
    for (ll n, m; t--; ) {
        scanf("%lld%lld", &n, &m);
        cnt1=cnt2=0;
        for (int i=0; i<N; i++) {
            if ((m>>i)&1) {
                if (i&1) cnt2++;
                else cnt1++;
            }
        }
        int ans=0, tp;
        for (int i=0; i<=cnt1; i++) {
            for (int j=0; j<=cnt2; j++) {
                tp=1LL*C[cnt1][i]*C[cnt2][j]%mod*qpow(F[i][j], n)%mod;
                if ((cnt1^cnt2^i^j)&1) tp=-tp;
                ans=(ans+tp)%mod;
            }
        }
        printf("%d\n", (ans+mod)%mod);
    }
    return 0;
}