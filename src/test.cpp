#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3fLL;
const int maxn=2e5+100;
const int mod=1e9+7;
struct ret {
    int a[3][3];
    ret(){memset(a, 0, sizeof(a));}
    ret operator * (const ret& aa) {
        ret ans;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    ans.a[i][j]=(ans.a[i][j]+1LL*a[i][k]*aa.a[k][j])%mod;
                }
            }
        }
        return ans;
    }
    void to1() {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i==j) a[i][j]=1;
                else a[i][j]=0;
            }
        }
    }
};
ret rqpow(ll n) {
    ret ans, ml;
    for (int i=0; i<3; i++) ml.a[0][i]=1;
    ml.a[1][0]=1; ml.a[2][1]=1;
    ans.to1();
    for (; n; n>>=1, ml=ml*ml) {
        if (n&1) ans=ans*ml;
    }
    return ans;
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
    ios::sync_with_stdio(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ret aa, bb, cc;
    aa.a[2][0]=1; bb.a[1][0]=1; cc.a[0][0]=1;
    ret tmp=rqpow(a);
    aa=tmp*aa; 
    bb=tmp*bb; 
    cc=tmp*cc;
    int na=aa.a[2][0], nb=bb.a[2][0], nc=cc.a[2][0];
    ll ans=1;
    ans=ans*qpow(a, na)%mod*qpow(b, nb)%mod*qpow(c, nc)%mod;
    
    return 0;
}