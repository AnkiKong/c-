#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=5e5;
struct Pal {
    int nxt[N][27], fail[N], cnt[N], num[N], len[N], S[N], last, n, p;
    int newNode(int l) {
        memset(nxt[p], 0, sizeof(nxt[p]));
        cnt[p]=num[p]=0; len[p]=l;
        return p++;
    }
    void init() {
        p=0; newNode(0); newNode(-1);
        last=0; n=0; fail[0]=1; S[0]=-1;
    }
    int getFail(int x) {
        for (; S[n-len[x]-1]!=S[n]; x=fail[x]);
        return x;
    }
    void add(int c) {
        c-='a';
        S[++n]=c;
        int cur=getFail(last);
        if (!nxt[cur][c]) {
            int now=newNode(len[cur]+2);
            fail[now]=nxt[getFail(fail[cur])][c];
            nxt[cur][c]=now;
            num[now]=num[fail[now]]+1;
        }
        last=nxt[cur][c];
        cnt[last]++;
    }
    void count() {
        for (int i=p-1; ~i; i--) cnt[fail[i]]+=cnt[i];
    }
}pal;
struct SAM {
    int len[N<<1], fa[N<<1], son[N<<1][27];
    int ed[N<<1];
    int sz, last;
    ll diff;
    void init() {sz=last=1; diff=0;}
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
    ll count() {
        ll ans=0;
        for (int i=2; i<=sz; i++) ans+=len[i]-len[fa[i]];
        return ans;
    }
    void Ins(char *str) {
        init();
        for (int i=0; str[i]; i++) {
            ins(str[i]);
        }
    }
}sam;
char s[N];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // cout << (150-'a') << endl;
    pal.init(); sam.init();
    scanf("%s", s);
    int len=strlen(s);
    for (int i=0; i<len; i++) {
        pal.add(s[i]);
        sam.ins(s[i]);
    }
    sam.ins('a'+27);
    for (int i=len-1; ~i; i--) {
        sam.ins(s[i]);
    }
    ll ans=sam.count()-(len+1LL)*(len+1LL)+pal.p-2;
    ans/=2;
    cout << ans << endl;
    return 0;
}