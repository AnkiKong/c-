#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
// typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e7;
int p[maxn], pCnt;
__int128 s[maxn], sum[maxn];
bool inp[maxn];
void init() {
    s[1]=1; // s[i] i约数和
    for (int i=2; i<maxn; i++) {
        if (!inp[i]) {
            p[pCnt++]=i;
            sum[i]=s[i]=i+1;
            // phi[i]=i-1; mu[i]=-1;
        }
        for (int j=0; j<pCnt && i*p[j]<maxn; j++) {
            inp[i*p[j]]=1;
            if(i%p[j]==0) {
                sum[i*p[j]]=sum[i]*p[j]+1;
                s[i*p[j]]=s[i]/sum[i]*sum[i*p[j]];
                break;
            }
            s[i*p[j]]=s[i]*(p[j]+1);
            sum[i*p[j]]=1+p[j];
        }
    }
}
void print(__int128 a) {
    if (a>9) 
        print(a/10);
    putchar((int)(a%10)+'0');
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    for (int i=1; i<maxn; i++) s[i]+=s[i-1];
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        ull nn; scanf("%llu", &nn);
        __int128 ans=0, n=nn;
        for (__int128 i=1; i<=n; ) {
            __int128 tmp=0, b=n/(n/i);
            if (n/i<maxn) {
                tmp=s[n/i];
            } else {
                for (__int128 j=1, lit=n/i, a; j<=lit; ) {
                    a=lit/(lit/j);
                    __int128 c=(j+a)*(a-j+1);
                    tmp+=c/2*(lit/j);
                    j=a+1;
                }
            }
            ans+=(i+b)*(b-i+1)/2*tmp;
            i=b+1;
        }
        for (__int128 i=1; i*i<=n; i++) ans+=i*i*(n/(i*i));
        ans=(__int128)(n+1)*n/2*n-ans/2;
        print(ans);
        puts("");
    }
    return 0;
}