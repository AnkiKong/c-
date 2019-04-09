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
const int maxn=510;
bitset<maxn> mp[maxn], nxt, now, ss;
bool query(int a, int b) {
    if (a==b) return 1;
    now=nxt=mp[a];
    nxt[a]=0;
    int x;
    while ((x=nxt._Find_first())!=maxn) {
        nxt[x]=0;
        nxt|=(now|mp[x])^now;
        now|=mp[x];
        if (now[b]) return 1;
    }
    return now[b];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char op[10];
    int n, m, a, b;
    int TT=0;
    while (~scanf("%d%d", &n, &m)) {
        for (int i=0; i<n; i++) {
            mp[i]=ss; mp[i][i]=1;
        } 
        if (TT) puts("");
        printf("Case %d:\n", ++TT);
        while (m--) {
            scanf("%s%d%d", op, &a, &b);
            a--, b--;
            if (op[0]=='I') {
                mp[a][b]=mp[b][a]=1;
            } else if (op[0]=='D') {
                mp[a][b]=mp[b][a]=0;
            } else {
                if (query(a, b)) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}