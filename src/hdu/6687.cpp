#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
int nxt[maxn<<8][2], cnt[maxn<<8];
int tot, rt1, rt2;
inline int newNode() {
    nxt[tot][0]=nxt[tot][1]=cnt[tot]=0;
    return tot++;
}
void ins(int rt, int val) {
    int nw=rt;
    for (int i=30; ~i; i--) {
        int &tp=nxt[nw][(val>>i)&1];
        if (!tp) tp=newNode();
        nw=tp; cnt[tp]++;
    }
}
ll ans;
void query(int val, int nw1, int nw2, int dep) {
    if (dep<0) {
        ans+=val; return;
    }
    int *rt1=nxt[nw1], *rt2=nxt[nw2];
    while (cnt[rt1[0]] && cnt[rt2[1]]) {
        cnt[rt1[0]]--; cnt[rt2[1]]--;
        query(val|(1<<dep), rt1[0], rt2[1], dep-1);
    }
    while (cnt[rt1[1]] && cnt[rt2[0]]) {
        cnt[rt1[1]]--; cnt[rt2[0]]--;
        query(val|(1<<dep), rt1[1], rt2[0], dep-1);
    }
    while (cnt[rt1[1]] && cnt[rt2[1]]) {
        cnt[rt1[1]]--; cnt[rt2[1]]--;
        query(val, rt1[1], rt2[1], dep-1);
    }
    while (cnt[rt1[0]] && cnt[rt2[0]]) {
        cnt[rt1[0]]--; cnt[rt2[0]]--;
        query(val, rt1[0], rt2[0], dep-1);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1, n; TT <= T; TT++) {
        scanf("%d", &n);
        tot=0; ans=0;
        rt1=newNode(); rt2=newNode();
        for (int i=0, a; i<n; i++) {
            scanf("%d", &a);
            ins(rt1, a);
        }
        for (int i=0, a; i<n; i++) {
            scanf("%d", &a);
            ins(rt2, a);
        }
        query(0, rt1, rt2, 30);
        printf("%lld\n", ans);
    }
    return 0;
}