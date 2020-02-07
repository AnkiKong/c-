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
const int maxn=1e5;
ll p[maxn];
bool vis[maxn];
map<ll, int>cnt;
int pCnt;
void init() {
    for (int i=2; i<maxn; i++) {
        if (!vis[i]) p[pCnt++]=i;
        for (int j=0; j<pCnt && p[j]*i<maxn; j++) {
            vis[i*p[j]]=1;
            if (i%p[j]==0) break;
        }
    }
}
ll da1[maxn], da2[maxn];
void deal(int id) {
    ll ans1=1, ans2=1;
    ll tmp=da1[id];
    for (int i=0; p[i]*p[i]*p[i]<=tmp; i++) {
        int tot=0;
        while (tmp%p[i]==0) {
            tot++;
            tmp /= p[i];
        }
        tot%=3;
        if (tot==1) {
            ans1*=p[i];
            ans2*=p[i]*p[i];
        } else if (tot==2) {
            ans1*=p[i]*p[i];
            ans2*=p[i];
        }
    }
    ll sqrTmp=sqrt(tmp);
    if (sqrTmp*sqrTmp==tmp) {
        ans1*=tmp;
        ans2*=sqrTmp;
    } else {
        ans1*=tmp;
        ans2*=tmp*tmp;
    }
    da1[id]=ans1; da2[id]=ans2;
    cnt[ans1]++;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; 
    init();
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf(lld, da1+i);
        deal(i);
    }
    int ans=0;
    if (cnt[1]) ans++, cnt[1]=0;
    for (int i=0; i<n; i++) {
        ans += max(cnt[da1[i]], cnt[da2[i]]);
        cnt[da1[i]]=cnt[da2[i]]=0;
    }
    printf("%d", ans);
    return 0;
}