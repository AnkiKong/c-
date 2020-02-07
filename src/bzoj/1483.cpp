#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
int c[maxn], nc[maxn];
int head[maxn], nxt[maxn], sz[maxn], ed[maxn];
int ans;
void mege(int a, int b) {
    if (!sz[a]) return;
    sz[b] += sz[a];
    for (int i = head[a]; ~i; i = nxt[i]) {
        if (c[i-1] == b) ans--;
        if (c[i+1] == b) ans--;
    }
    for (int i = head[a]; ~i; i = nxt[i]) {
        c[i] = b;
    }
    nxt[ed[b]] = head[a], ed[b] = ed[a];
    head[a] = -1, ed[a] = -1, sz[a] = 0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    memset(head, -1, sizeof(head));
    memset(ed, -1, sizeof(ed));
    memset(c, -1, sizeof(c));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
        nc[c[i]] = c[i];
        if (c[i] != c[i-1]) ans++;
        if (ed[c[i]] == -1) ed[c[i]] = i;
        sz[c[i]]++, nxt[i] = head[c[i]], head[c[i]] = i;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d", &b, &c);
            if (c == b) continue;
            if (sz[nc[b]] > sz[nc[c]]) swap(nc[c], nc[b]);
            mege(nc[b], nc[c]);
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}