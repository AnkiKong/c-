#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
const int mod=1000000007;
char str[30];
bool vis[30];
vector<pii> loop;
int n;
ll lcm(int a, int b) {
    return a/__gcd(a, b)*b;
}

ll qpow(ll a, int b) {
    ll ans=1; a%=mod;
    for (; b; b>>=1, a=a*a%mod) {
        if (b&1) ans=ans*a%mod;
    }
    return ans;
}
vector<ll> wait;
ll func() {
    ll ans=0;
    int len=wait.size();
    for (int i=1; i<(1<<len); i++) {
        ll flag=-1, cnt=0, sum=0;
        for (int j=0; j<len; j++) {
            if ((i>>j)&1) {
                sum+=wait[j]; cnt++;
            }
        }
        if (!((cnt^len)&1)) flag=1;
        ans=(ans+qpow(sum, n)*flag)%mod;
    }
    return (ans+mod)%mod;
}
int solve(int n) {
    memset(vis, 0, sizeof(vis));
    loop.clear();
    map<int,int> cnt;
    for (int i=0; i<26; i++) {
        if (vis[i]) continue;
        vis[i]=1; int x=str[i]-'a', len=1;
        while (x!=i) {
            vis[x]=1; x=str[x]-'a'; len++;
        }
        cnt[len]++;
    }
    for (pii a:cnt) {
        loop.push_back(a);
    }
    ll ans=0, len=loop.size();
    for (int i=1; i<(1<<len); i++) {
        ll anss=1; wait.clear();
        for (int j=0; j<len; j++) {
            if ((i>>j)&1) {
                anss=lcm(anss, loop[j].first);
                wait.push_back(loop[j].first*loop[j].second);
            }
        }
        ans=(ans+anss*func()%mod)%mod;
    }
    return ans%mod;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (; t--; ) {
        scanf("%d%s", &n, str);
        printf("%d\n", solve(n));
    }
    return 0;
}