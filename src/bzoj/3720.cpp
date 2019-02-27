#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int head[maxn], to[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a], head[a] = vcnt;
}
int Head[maxn], To[maxn<<1], Nxt[maxn<<1], Vcnt;
void Add(int a, int b) {
    To[++Vcnt] = b; Nxt[Vcnt] = Head[a], Head[a] = Vcnt;
}
int n, m, bls;
struct node {
    int da[260], sz;
    node() {sz=0; memset(da, 0, sizeof(da));}
    void ins(int x) {
        // da[++sz] = x;
        // sort(da + 1, da + 1 + sz);
        int pos = ++sz;
        for (int i = sz; i > 1 && da[i-1] > x; i--) da[i] = da[i-1], pos = i - 1;
        da[pos] = x;
    }
    void modify(int val, int nval) {
        int pos = lower_bound(da + 1, da + 1 + sz, val) - da;
        for (; pos < sz && da[pos+1] < nval; pos++) da[pos] = da[pos+1];
        for (; pos > 1 && da[pos-1] > nval; pos--) da[pos] = da[pos-1];
        da[pos] = nval;  
    }
    int query(int x) {
        return sz - (lower_bound(da + 1, da + sz + 1, x) - da) + 1;
    }
}tr[20000];
int fa[maxn], belong[maxn], cnt;
int da[maxn];
void dfs(int u) {
    if (tr[belong[fa[u]]].sz >= bls) {
        cnt++; belong[u] = cnt; tr[cnt].ins(da[u]); Add(belong[fa[u]], cnt);
    } else {
        belong[u] = belong[fa[u]]; tr[belong[u]].ins(da[u]);
    }
    for (int i = head[u]; i; i = nxt[i]) {
        if (to[i] == fa[u]) continue;
        fa[to[i]] = u, dfs(to[i]);
    }
}
int ans;
void getBls(int x, int val) {
    ans += tr[x].query(val);
    for (int i = Head[x]; i; i = Nxt[i]) {
        getBls(To[i], val);
    }
}
void getPer(int x, int val) {
    if (da[x] > val) ans++;
    for (int i = head[x]; i; i = nxt[i]) {
        if (to[i] == fa[x]) continue;
        if (belong[x] != belong[to[i]]) getBls(belong[to[i]], val);
        else getPer(to[i], val);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n); bls = sqrt(n);
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b); 
        add(a, b), add(b, a);
    }
    for (int i = 1; i <= n; i++) scanf("%d", da + i);
    belong[0] = 1;
    dfs(1); scanf("%d", &m);
    for (int i = 0, op, a, b; i < m; i++) {
        scanf("%d%d%d", &op, &a, &b);
        a ^= ans, b ^= ans;
        if (op == 0) {
            ans = 0; getPer(a, b);
            printf("%d\n", ans);
        } else if (op == 1) {
            tr[belong[a]].modify(da[a], b);
            da[a] = b;
        } else if (op == 2) {
            da[++n] = b; add(a, n); add(n, a); fa[n] = a;
            if (tr[belong[a]].sz >= bls) cnt++, belong[n] = cnt, tr[cnt].ins(b), Add(belong[a], cnt);
            else tr[belong[a]].ins(b), belong[n] = belong[a];
        }
    }
    return 0;
}