#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
char str1[maxn], str2[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s", str1, str2);
    int len1=strlen(str1), len2=strlen(str2);
    for (int i=len1; i<maxn; i++) str1[i]=str1[i-len1];
    int sumt
    int l=0, r=0, cnt0=0, cnt1=0;
    int mx=0, mxl, mxr;
    for (; r<maxn; r++) {
        if (str1[r]=='0') cnt0++;
        else cnt1++;
        
    }
    return 0;
}