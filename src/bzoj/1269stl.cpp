#include <bits/stdc++.h>
#include <ext/rope>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e6+100;
char str1[maxn], str2[maxn];
rope<char> da, revda, tmp;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, x, now=0, len; scanf("%d", &n);
    char opt[50];
    while (n--) {
        scanf("%s", opt);
        len=da.length();
        if (opt[0]=='I') {
            scanf("%d%*c", &x);
            for (int i=0; i<x; i++) {
                str1[i]=getchar();
                str2[x-i-1]=str1[i];
            }
            str1[x]=str2[x]=0;
            da.insert(now, str1);
            revda.insert(len-now, str2);
        } else if (opt[0]=='M') {
            scanf("%d", &x); now=x;
        } else if (opt[0]=='D') {
            scanf("%d", &x);
            da.erase(now, x);
            revda.erase(len-now-x, x);
        } else if (opt[0]=='R') {
            scanf("%d", &x);
            tmp=da.substr(now, x);
            da=da.substr(0, now)+revda.substr(len-now-x, x)+da.substr(now+x, len-now-x);
            revda=revda.substr(0, len-now-x)+tmp+revda.substr(len-now, now);
        } else if (opt[0]=='G') {
            printf("%c\n", da[now]);
        } else if (opt[0]=='P') {
            now--;
        } else if (opt[0]=='N') {
            now++;
        }
    }
    return 0;
}