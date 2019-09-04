#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
int phi[maxn];
int pri[maxn];
bool inp[maxn];
int tot;
void get() {
    phi[1]=1;
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) pri[tot++]=i, phi[i]=i-1;
        for (int j=0; j<tot && 1LL*pri[j]*i<maxn; j++) {
            inp[i*pri[j]]=1;
            if (i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j]; 
                break;
            } else {
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }
        }
    }
}
bool flag;
int qpow(ll a, int b, int mod) {
    ll ans=1;
    bool flag2=false;
    for (; b; b>>=1) {
        if (b&1) {
            if (flag2 || ans*a>=mod) flag=true;
            ans=ans*a%mod;
        }
        if (a*a>=mod) flag2=true;
        a=a*a%mod;
    }
    return ans;
}
int dfs(int a, int b, int mod) {
    if (mod<=1) {
        flag=1;
        return 0;
    } 
    if (b<=0) return 1;
    int tp=dfs(a, b-1, phi[mod]);
    if (tp>=phi[mod]) flag=true;
    if (flag) return qpow(a, tp%phi[mod]+phi[mod], mod);
    else return qpow(a, tp, mod);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    get();
    // for (int i=1; i<200; i++) cout << phi[i] << "\n";
    IOS;
    int t; cin >> t;
    for (int a, b, m; t--; ) {
        cin >> a >> b >> m;
        if (a==1) {
            if (m==1) cout << 0 << "\n";
            else cout << 1 << "\n";
            // cout << (m!=1) << "\n";
        } else {
            flag=0;
            cout << dfs(a, b, m) << "\n";
        }
    }
    return 0;
}