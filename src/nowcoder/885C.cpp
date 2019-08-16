#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e7;
ll qpow(ll a, ll b, ll mod) {
    a%=mod; ll ans=1;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
int head[N], nxt[N], tot;
ll num[N], id[N];
void add(ll idd, ll val) {
    num[++tot]=val; id[tot]=idd; nxt[tot]=head[val%N]; head[val%N]=tot;
}
ll query(ll val) {
    int ids=val%N;
    for (int i=head[ids]; i; i=nxt[i]) {
        if (num[i]==val) return id[i];
    }
    return -1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int T; cin >> T;
    // unordered_map<ll,int> as;
    for (int TT = 1; TT <= T; TT++) {
        // as.clear(); 
        memset(head, 0, sizeof(head)); tot=0;
        ll n, x0, a, b, p;
        cin >> n >> x0 >> a >> b >> p;
        ll m=1000;
        ll num=(p+m-1)/m;
        ll am=qpow(a, m, p), pm=am;
        for (int i=1; i<=num; i++) {
            // if (!as.count(pm)) as[pm]=i*m;
            if (query(pm)==-1) add(i*m, pm);
            pm=pm*am%p;
        }

        int q;
        for (cin>>q; q--; ) {
            ll ans, v; cin >> v;
            if (a==0) {
                if (v==x0) ans=0;
                else if (v==b && n>1) ans=1;
                else ans=-1;
            } else if (a==1) {
                if (b==0) {
                    if (v==x0) ans=0;
                    else ans=-1;
                } else {
                    // cout << "here\n";
                    ans=(v-x0+p)*qpow(b, p-2, p)%p;
                    if (ans>=n) ans=-1;
                }
            } else {
                v=(v*(a-1)+b)%p;
                ll X=(x0*(a-1)+b)%p;
                if (X==0) {
                    if (v==0) ans=0;
                    else ans=-1;
                } else {
                    // cout << "here";
                    v=v*qpow(X, p-2, p)%p;
                    ans=linf;
                    if (v==1) {
                        ans=0;
                    } else {
                        ll pw=1, ids;
                        for (int i=0; i<=m; i++) {
                            // if (as.count(pw*v%p)) ans=min(ans, 1LL*as[pw*v%p]-i);
                            if ((ids=query(pw*v%p))!=-1) ans=min(ans, ids-i);
                            pw=pw*a%p;
                        }
                        if (ans>=n) ans=-1;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}