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
int fac[maxn], ans[maxn];
void exgcd(ll a, ll b, ll& d, ll&x, ll& y) {
    if (!b) {
        d = a, x = 1, y = 0;
    } else {
        exgcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}
ll inv(ll a, ll mod) {
    ll x, y, d;
    exgcd(a, mod, d, x, y);
    return (x%mod+mod)%mod;
}
bool inp[maxn];
int p[664581 + 100], cnt;
void getP() {
    for (int i = 2; i < maxn; i++) {
        if (!inp[i]) p[cnt++] = i;
        for (int j = 0; j < cnt && 1LL * i * p[j] < maxn; j++) {
            inp[i*p[j]] = 1;
            if (i%p[j] == 0) break;
        }
    }
}
ll invs[maxn];
void getInv(int mod) {
    invs[1] = 1;
    for (int i = 2; i < maxn; i++) {
        invs[i] = 1LL * invs[mod%i] * (mod-mod/i) % mod;
    }
}
void init(int mod) {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) 
        fac[i] = 1LL * fac[i-1] * i % mod;
    getP();
    // getInv(mod);
    ans[1] = 1;
    for (int i = 0; i < cnt; i++) {
        // ll t = 1LL * ans[p[i]-1]*(p[i]-1)%mod*invs[p[i]%mod]%mod;
        ll t = 1LL * ans[p[i]-1]*(p[i]-1)%mod*inv(p[i]%mod, mod)%mod;
        for (int j = p[i]; j < p[i+1]; j++) ans[j]=t;
    }
    // printf("%d\n", cnt);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t, mod; scanf("%d%d", &t, &mod);
    init(mod);
    int n, m;
    while(t--){
        scanf("%d%d", &n, &m);
        printf(lld "\n", 1LL * fac[n]*ans[m]%mod);
    }
    
    return 0;
}