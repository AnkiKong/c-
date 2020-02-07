#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
ll a[maxn];
struct node {
    ll l, r;
    mutable ll v;
    node(ll L, ll R=-1, ll V=0):l(L), r(R), v(V) {}
    bool operator < (const node& tmp) const {
        return l < tmp.l;
    }
};
set<node> s;
ll seed;
ll rnd() {
    ll res=seed;
    seed=(seed*7+13)%mod;
    return res;
}
auto split(ll pos) {
    auto it=s.lower_bound(node(pos));
    if (it!=s.end() && it->l==pos) {
        return it;
    }
    --it;
    ll l=it->l, r=it->r, v=it->v;
    s.erase(it);
    s.insert(node(l, pos-1, v));
    return s.insert(node(pos, r, v)).first;
}
void assign(ll l, ll r, ll val) {
    auto itr=split(r+1), itl=split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}
void add(ll l, ll r, ll val) {
    auto itr=split(r+1), itl=split(l);
    for (; itl != itr; itl++) {
        itl->v += val;
    }
}
ll qpow(ll a, ll b, ll mod) {
    ll res=1; a%=mod;
    for (; b; a=a*a%mod, b>>=1) {
        if (b&1) {
            res=res*a%mod;
        }
    }
    return res;
}

ll sum(ll l, ll r, ll ex, ll md) {
    auto itr=split(r+1), itl=split(l);
    ll res=0;
    for (; itl!=itr; itl++) {
        res=(res+(itl->r - itl->l + 1)%md*qpow(itl->v, ex, md)%md)%md;
    }
    return res;
}
ll askK(ll l, ll r, ll k) {
#define pii pair<ll, ll>
    vector<pii > vp;
    auto itr=split(r+1), itl=split(l);
    for (; itl != itr; itl++) {
        vp.push_back(pii(itl->v, itl->r-itl->l+1));
    }
    sort(vp.begin(), vp.end());
    for (auto a:vp) {
        k -= a.second;
        if (k<=0) {
            return a.first;
        }
    }
#undef pii
    return -1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n, m, vmax;
    scanf("%lld%lld%lld%lld", &n, &m, &seed, &vmax);
    ll op, l, r, x, y;
    for (int i=1; i<=n; i++) {
        a[i]=rnd()%vmax+1;
        s.insert(node(i, i, a[i]));
    }
    while (m--) {
        op=rnd()%4+1;
        l=rnd()%n+1; r=rnd()%n+1;
        if (l>r) swap(l, r);
        if (op==3) {
            x=rnd()%(r-l+1)+1;
        } else {
            x=rnd()%vmax+1;
        }
        if (op==4) {
            y=rnd()%vmax+1;
        }
        if (op==1) {
            add(l, r, x);
        } else if (op==2) {
            assign(l, r, x);
        } else if (op==3) {
            printf("%lld\n", askK(l, r, x));
        } else {
            printf("%lld\n", sum(l, r, x, y));
        }
    }
    return 0;
}