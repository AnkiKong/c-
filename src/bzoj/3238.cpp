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
const int maxn=5e5+100;
int n;
struct sam {
//点i ii上面表示子串的数量为len[fa[i]]−len[i]
//在parents上，父亲是儿子上的子串的公共后缀
//父亲上的子串出现次数，是儿子上的子串出现次数之和
//在一个点上的子串，短的为长的的后缀
//len数组表示的是这个节上的子串最长长度

    int len[maxn<<1], fa[maxn<<1], son[maxn<<1][26];
    int ed[maxn<<1];
    int sz, last;
    void init() {sz=last=1;}
    void ins(char c) {
        int s=c-'a';
        int p=last, np=++sz; 
        last=np; ed[np]=1; len[np]=len[p]+1;
        for (; p && !son[p][s]; p=fa[p]) son[p][s]=np;
        if (!p) fa[np]=1;
        else {
            int q=son[p][s];
            if (len[p]+1==len[q]) fa[np]=q;
            else {
                int nq=++sz; len[nq]=len[p]+1;
                memcpy(son[nq], son[q], sizeof(son[q]));
                fa[nq]=fa[q]; fa[q]=fa[np]=nq;
                for (; q==son[p][s] && p; p=fa[p]) son[p][s]=nq;
            }
        }
    }
    void Ins(char *str) {
        init();
        for (int i=0; str[i]; i++) {
            ins(str[i]);
        }
    }
    int x[maxn<<1], y[maxn<<1];
    void msort() {
        for (int i=1; i<=sz; i++) x[len[i]]++;
        for (int i=1; i<=sz; i++) x[i]+=x[i-1];
        for (int i=1; i<=sz; i++) y[x[len[i]]--]=i;
    }
    void solve() {
        // for (int i=sz; i; i--) ed[fa[y[i]]]+=ed[y[i]];
        ll ans1=1LL*n*(n+1)/2*(n-1), ans2=0;
        for (int i=sz; i; i--) {
            int tp = y[i];
            ans2+=1LL*ed[fa[tp]]*len[fa[tp]]*ed[tp];
            ed[fa[tp]]+=ed[tp];
        }
        printf("%lld", ans1-ans2*2);
    }
};
char str[maxn];
sam Sam;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    n=strlen(str);
    Sam.init();
    for (int i=n-1; ~i; i--) 
        Sam.ins(str[i]);
    Sam.msort();
    Sam.solve();
    return 0;
}