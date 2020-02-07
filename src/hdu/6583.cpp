#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
int n;
struct sam {
    int len[maxn<<1], fa[maxn<<1], son[maxn<<1][26];
    int ed[maxn<<1];
    int sz, last, root;
    void init() {
        sz=last=1; memset(son[1], 0, sizeof(son[1]));
    }
    int newNode() {
        ++sz; memset(son[sz], 0, sizeof(son[sz]));
        return sz;
    }
    void ins(char c) {
        int s=c-'a';
        int p=last, np=newNode();
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
    int getNxt(int nw, int c, int& lens) {
        c-='a';
        if (son[nw][c]) {
            lens++; return son[nw][c];
        } else {
            while (nw && !son[nw][c]) nw=fa[nw];
            if (nw) lens=len[nw]+1, nw=son[nw][c];
            else lens=0, nw=1;
            return nw;
        }
    }
    int getLen(int nw, int c, int& lens) {
        c-='a';
        if (son[nw][c]) {
            lens++;
        } else {
            while (nw && !son[nw][c]) 
                nw=fa[nw];
            if (nw) lens=len[nw]+1;
            else lens=0;
        }
        return lens;
    }
}SAM;
char s[maxn];
ll dp[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int p, q; ~scanf("%s%d%d", s+1, &p, &q); ) {
        int len=strlen(s+1);
        SAM.init(); dp[0]=0;
        int now=1, j=0, mxLen=0;
        for (int i=1; i<=len; i++) {
            dp[i]=dp[i-1]+p;
            if (SAM.getLen(now, s[i], mxLen)+j>=i) {
                dp[i]=min(dp[i], dp[j]+q);
                now=SAM.getNxt(now, s[i], mxLen);
            } else {
                while (SAM.getLen(now, s[i], mxLen)+j<i) {
                    SAM.ins(s[++j]);
                }
                now=SAM.getNxt(now, s[i], mxLen);
                if (j<i) dp[i]=min(dp[i], dp[j]+q);
            }
        }
        printf("%lld\n", dp[len]);
    }
    return 0;
}