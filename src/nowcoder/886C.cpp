#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=2e5;
struct Pal {
    int nxt[N][26], fail[N], cnt[N], num[N], len[N], S[N], last, n, p;
    bool vis[N];
    ll ans, res;
    int newNode(int l) {
        memset(nxt[p], 0, sizeof(nxt[p]));
        cnt[p]=num[p]=0; len[p]=l;
        return p++;
    }
    void init() {
        p=0; newNode(0); newNode(-1);
        last=0; n=0; fail[0]=1; S[0]=-1;
        ans=0; res=0;
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
    void dfs(int x) {
        vector<int> vs;
        for (int i=x; i>1 && !vis[i]; i=fail[i]) {
            res++; vs.push_back(i); vis[i]=1;
        }
        ans+=res;
        for (int i=0; i<26; i++) {
            if (nxt[x][i]) dfs(nxt[x][i]);
        }
        for (int a:vs) vis[a]=0, res--;
    }
}pal;
char s[N];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%s", s);
        pal.init();
        for (int i=0; s[i]; i++) pal.add(s[i]);
        pal.ans=2-pal.p;
        pal.dfs(0); 
        pal.dfs(1);
        printf("Case #%d: %lld\n", TT, pal.ans);
    }
    return 0;
}