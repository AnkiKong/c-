// #include <bits/stdc++.h>
#include <stdio.h>
#include <map>

#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
// const int maxn=;
int da[30], da2[30];
map<int, int> vis;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    char str[30];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int tmp = 0;
        for (int j = 0; str[j]; j++) {
            tmp |= 1<<(str[j]-'A');
        }
        da[i] = tmp;
        // printf("%d\n", tmp);
    }
    int m = n>>1;
    int ansCnt=0, l=0, r=0;
    for (int i = 0; i < (1<<m); i++) {
        int cnt = 0, s = 0;
        for (int j = 0; j <= m; j++) if (i&(1<<j)) s^=da[j], cnt++;
        // if (cnt > vis[s]) vis[s] = i;
        // vis[s] = max(vis[s], cnt);
        if (vis[s]==0) vis[s] = i;
        else if (__builtin_popcount(vis[s]) < cnt) vis[s] = i;
        if (!s && cnt>ansCnt) ansCnt=cnt, l=i,r=0;
    }
    int mm = n - m;
    for (int i = 0; i < mm; i++) da2[i] = da[i+m];
    for (int i = 0; i < (1<<mm); i++) {
        int cnt = 0, s = 0;
        for (int j = 0; j <= m; j++) if (i&(1<<j)) s^=da2[j], cnt++;
        if (vis.count(s) && __builtin_popcount(vis[s]) + cnt > ansCnt) 
            ansCnt=__builtin_popcount(vis[s])+cnt, l=vis[s], r=i;
        if (!s && cnt>ansCnt) 
            ansCnt=cnt, l=i,r=0;
    }
    printf("%d\n", ansCnt);
    for (int i = 0; i < m; i++) if (l&(1<<i)) printf("%d ", i+1);
    for (int i = 0; i < mm;i++) if (r&(1<<i)) printf("%d ", i+m+1);
    return 0;
}