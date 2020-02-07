#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
int qpow(ll a, int b, int mod) {
    ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans%mod;
}
int getG(int n) {
    if (n==2) return 1;
    vector<int> p;
    int phi=n-1;
    for (int i=2; i*i<=phi; i++) {
        if (phi%i==0) {
            while (phi%i==0) phi/=i;
            p.push_back(i);
        }
    }
    if (phi>1) p.push_back(phi);
    for (int i=2; i<n; i++) {
        bool flag=1;
        for (int j:p) {
            if (qpow(i, (n-1)/j, n)==1) {
                flag=0; break;
            }
        }
        if (flag) return i;
    }
    return -1;
}
int x[maxn], I[maxn];
int cnt[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int t; cin >> t;
    for (int n; t--; ) {
        cin >> n;
        memset(cnt, 0, n<<2);
        int g=getG(n);
        I[0]=1; x[0]=1;
        for (int i=1; i<n; i++) {
            x[i]=1LL*x[i-1]*g%n;
            I[x[i]]=i;
        }
        for (int i=1; i<n; i++) {
            cnt[x[1LL*I[i]*i%(n-1)]]++;
        }
        ll ans=0;
        for (int i=1; i+i<=n; i++) {
            ans+=1LL*cnt[i]*cnt[n-i];
        }
        cout << ans << "\n";
    }
    return 0;
}