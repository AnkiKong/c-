#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1)|1
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
const int mod=1000000007;
char str[30];
bool vis[30];
int qpow(ll a, int b) {
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
    int t, n; scanf("%d", &t);
    for (; t; t--) {
        scanf("%d%s", &n, str);
        map<int,int> cnt;
        for (int i=0; i<26; i++) {
            if (vis[i]) continue;
            vis[i]=1;
            int len=0, j=str[i]-'a';
            for (; j!=i; j=str[j]-'a', len++) i=j, vis[j]=1;
            cnt[len]++;
        }
        int tCnt=cnt.size();
        for (int i=1; i<(1<<tCnt); i++) {
            ll ans=1;
            
        }
    }
    
    return 0;
}