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
const int maxn=1e5+100;
int n, k;
set<int> vis[maxn<<1];
int head[maxn<<1], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt]=b; nxt[vcnt]=head[a]; head[a]=vcnt;
}
ll ans[maxn<<1], cnt[maxn<<1];
typedef set<int>::iterator sIter;
struct Sam {
    int len[maxn<<1], fa[maxn<<1], son[maxn<<1][26];
    int ed[maxn<<1];
    int sz, last;
    void init() {sz=last=1;}
    void ins(char c, int id) {
        int s=c-'a';
        int p=last, np=++sz;
        last=np; ed[np]=id; len[np]=len[p]+1; vis[np].insert(id);
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
    void deal() {
        for (int i=2; i<=sz; i++) add(fa[i], i);
    }
    void dfs(int x) {
        for (int i=head[x]; i; i=nxt[i]) {
            int t=to[i];
            dfs(t);
            if (vis[t].size()>vis[x].size()) swap(vis[t], vis[x]);
            for (sIter i=vis[t].begin(); i!=vis[t].end(); i++) {
                vis[x].insert(*i);
            }
            vis[t].clear();
        }
        if ((int)vis[x].size()>=k) cnt[x]=len[x]-len[fa[x]];
    }
    void dfs2(int x, ll Cnt) {
        Cnt+=cnt[x];
        if (ed[x]) ans[ed[x]]+=Cnt;
        for (int i=head[x]; i; i=nxt[i]) dfs2(to[i], Cnt);
    }
};
Sam sam;
char str[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    sam.init();
    for (int i=1; i<=n; i++) {
        scanf("%s", str);
        sam.last=1;
        for (int j=0; str[j]; j++) {
            sam.ins(str[j], i);
        }
    }
    sam.deal();
    sam.dfs(1);
    sam.dfs2(1, 0);
    for (int i=1; i<=n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}