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
const int maxn=3000;
int n, m;
int head[maxn], nxt[maxn*10], to[maxn*10], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}

struct node {
    int lit, id;
    // bool operator < (const node a) {
    //     return lit < a.lit;
    // }
}da[maxn];
bool cmp(node a, node b) {
    return a.lit < b.lit;
}
int q[maxn<<1], lit[maxn], ind[maxn], indt[maxn];
int solve(int x) {
    memcpy(indt, ind, sizeof(ind));
    int l = 0, h = 0;
    for (int i = 1, p = 1; i <= n; i++) {
        for ( ; p <= n && da[p].lit < i; p++) 
            if (!indt[da[p].id] && da[p].id != x) 
                q[h++] = da[p].id;
        if (h > l) {
            int u = q[l++];
            for (int j = head[u]; j; j = nxt[j]) {
                indt[to[j]]--;
                if (!indt[to[j]] && lit[to[j]] < i && to[j] != x) q[h++] = to[j];
            }
        } else return l;
    }
    return l;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        da[i].lit = n - a, da[i].id = i;
        lit[i] = n - a;
    } 
    sort(da+1, da+1+n, cmp);
    // printf("%d\n", da[1].lit);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(b, a); ind[a]++;
    }
    solve(0);
    for (int i = n - 1; i >= 0; i--) printf("%d%c", q[i], i == 0 ? '\n' : ' ');
    for (int i = 1; i <= n; i++) {
        printf("%d%c", n - solve(i), i == 0 ? '\n' : ' ');
    }
    return 0;
}