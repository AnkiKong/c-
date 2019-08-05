#include <bits/stdc++.h>
// #ifndef LOCAL
// #pragma GCC optimize(3)
// #endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
ll mod;
struct mat {
    ll a[2][2];
    mat(){memset(a, 0, sizeof(a));}
    mat operator* (const mat& A) const {
        mat ans;
        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++)
                    ans.a[i][j]+=a[i][k]*A.a[k][j]%mod;

        return ans;
    }
    void init() {
        for (int i=0; i<2; i++) a[i][i]=1;
    }
};
inline mat qpow(mat A, int b) {
    mat ans; ans.init();
    for (; b; b>>=1, A=A*A) {
        if (b&1) ans=ans*A;
    }
    return ans;
}
mat qpow(mat A, char* b, int len) {
    mat ans; ans.init();
    for (int i=len; i; i--) {
        int cnt=b[i]-'0';
        ans=ans*qpow(A, cnt);
        A=qpow(A, 10);
    }
    return ans;
}
char s[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll x0, x1, a, b;
    scanf("%lld%lld%lld%lld%s%lld", &x0, &x1, &a, &b, s+1, &mod);
    int len=strlen(s+1);
    s[len]--;
    for (int i=len; s[i]<'0' && i; i--) s[i-1]--, s[i]+=10;
    // printf("%s\n", s+1);
    mat A; A.a[0][0]=a; A.a[0][1]=b; A.a[1][0]=1; A.a[1][1]=0;
    A=qpow(A, s, len);
    ll ans=(A.a[0][0]*x1%mod+A.a[0][1]*x0%mod)%mod;
    printf("%lld\n", ans);
    return 0;
}