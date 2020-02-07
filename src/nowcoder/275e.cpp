#include <bits/stdc++.h>
#define pii pair<int, int>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
pii da[maxn];
int tr[maxn];
int n, m;
inline int lowbit(int a) {
    return a & -a;
}

void add(int loc, int val) {
    while (loc <= n) {
        tr[loc] += val;
        loc += lowbit(loc);
    }
}

int cal(int loc) {
    int ans = 0;
    while (loc) {
        ans += tr[loc];
        loc -= lowbit(loc);
    }
    return ans;
}
struct node {
    int l, r, k, id;
    void get(int i) {
        id = i;
        scanf("%d%d%d", &l, &r, &k);
    }
    bool operator < (const node &a) const {
        return k < a.k;
    }
} da2[maxn];
int ans[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        da[i] = pii(tmp, i);
    }
    for (int i = 0; i < m; i++) {
        da2[i].get(i);
    }
    sort(da + 1, da + n + 1);
    sort(da2, da2 + m);
    int j = 1;
    for (int i = 0; i < m; i++) {
        for ( ; da[j].first <= da2[i].k && j <= n; j++) {
            add(da[j].second, 1);
        }
        ans[da2[i].id] = cal(da2[i].r) - cal(da2[i].l - 1);
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}