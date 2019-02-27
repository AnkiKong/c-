#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
inline int lowbit(int x) {return -x & x;}
int sum[maxn];
int n, m;
void update(int x, int val) {
    for (; x <= n; x += lowbit(x)) sum[x] += val;
}
int cal(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += sum[x];
    return ans;
}
struct node {
    int t, loc, val;
}da[maxn], p[maxn];
// int da1[maxn], da2[maxn];
int locs[maxn];
ll ans[maxn];
void cdq(int L, int R) {
    if (L >= R) return;
    int mid = (L + R) >> 1;
    int l1 = L, l2 = mid + 1;
    for (int i = L; i <= R; i++) {
        if (da[i].t <= mid) p[l1++] = da[i];
        else p[l2++] = da[i];
    }
    for (int i = L; i <= R; i++) da[i] = p[i];
    l1 = L;
    for (int i = mid + 1; i <= R; i++) {
        for (; l1 <= mid && da[l1].loc < da[i].loc; l1++) {
            update(da[l1].val, 1);
        }
        ans[da[i].t] += l1 - L - cal(da[i].val);
    }
    for (int i = L; i < l1; i++) update(da[i].val, -1);
    l1 = mid;
    for (int i = R; i > mid; i--) {
        for (; l1 >= L && da[l1].loc > da[i].loc; l1--) {
            update(da[l1].val, 1);
        }
        ans[da[i].t] += cal(da[i].val-1);
    }
    for (int i = mid; i > l1; i--) update(da[i].val, -1);
    cdq(L, mid); cdq(mid+1, R);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &da[i].val); da[i].loc = i;
        locs[da[i].val] = i; da[i].t = -1;
    }
    int tii = n;
    for (int i = 0, a; i < m; i++) {
        scanf("%d", &a);
        da[locs[a]].t = tii--;
    }
    for (int i = 1; i <= n; i++) if (da[i].t == -1) da[i].t = tii--;
    cdq(1, n);
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
    }
    for (int i = n; i > n - m; i--) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}