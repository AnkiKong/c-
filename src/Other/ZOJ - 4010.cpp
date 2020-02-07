#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
ull base=131;
ull _b[maxn<<1], ha[maxn<<1];
char str[maxn];
int ans[maxn];
ull getHash(int l, int r) {
    return ha[r]-ha[l-1]*_b[r-l+1];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    _b[0]=1;
    for (int i=1; i<(maxn<<1); i++) _b[i]=_b[i-1]*base;
    int t; scanf("%d", &t);
    for (; t--; ) {
        scanf("%s", str+1);
        int len=strlen(str+1), l2=len*2;
        for (int i=1; i<len; i++) {
            str[i]-='a'-1;
            str[i+len]=str[i];
        }
        ha[0]=0;
        for (int i=1; i<l2; i++) {
            ha[i]=ha[i-1]*base+str[i];
        }
        memset(ans, 0, sizeof(ans));
        for (int i=1, j; i<l2-1; i=j+1) {
            for (j=i; j<l2-1 && str[j]!=str[j+1]; j++);
            int l=j-i+1;
            for (int k=2; k<=l && k<=len; k++) {
                if (getHash(i, j-k+1)!=getHash(i+k-1, j)) 
                    ans[len-k]=1;
            }
        }
        for (int i=0; i<len-1; i++) {
            putchar(ans[i]+'0');
        }
        puts("1");
    }

    return 0;
}