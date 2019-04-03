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
struct Sam {
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
    int sum[maxn<<1];
    void msort() {
        for (int i=1; i<=sz; i++) x[len[i]]++;
        for (int i=1; i<=sz; i++) x[i]+=x[i-1];
        for (int i=1; i<=sz; i++) y[x[len[i]]--]=i;
    }
    void solve(int t, int k) {
        for (int i=sz; i; i--) {
            if (t) ed[fa[y[i]]]+=ed[y[i]];
            else ed[i]=1;
        }
        ed[1]=0;
        for (int i=sz; i; i--) {
            int z=y[i];
            sum[z]=ed[z];
            for (int j=0; j<26; j++) {
                if (son[z][j]) {
                    sum[z]+=sum[son[z][j]];
                }
            }
        }
        if (sum[1]<k) {
            printf("-1");
            return;
        }
        int now=1;
        while (1) {
            if (k<=ed[now]) break;
            k-=ed[now];
            for (int i=0; i<26; i++) {
                if (sum[son[now][i]]<k) k-=sum[son[now][i]];
                else {
                    printf("%c", 'a'+i);
                    now=son[now][i];
                    break;
                }
            }
        }
    }
};
Sam sam;
char str[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    int t, k;
    scanf("%d%d", &t, &k);
    sam.Ins(str);
    sam.msort();
    sam.solve(t, k);
    return 0;
}