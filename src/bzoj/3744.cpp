#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
#define pii pair<int, int>
typedef long long ll;
inline int lowbit(int x) {return -x & x;}
const int inf=0x3f3f3f3f;
const int maxn=7e4;
int bls;
// ZhuXiShu
struct node {
    int l, r, sum;
} tr[int(1e6+100)];
int root[maxn], Tcnt = 1;
void ins(int num, int& x, int l, int r) {
    tr[Tcnt] = tr[x]; x = Tcnt++; tr[x].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (num <= mid) ins(num, tr[x].l, l, mid);
    else ins(num, tr[x].r, mid+1, r);
}
int query(int ss, int bs, int k, int l, int r) {
    if (l == r) return l;
    int d = tr[tr[bs].l].sum - tr[tr[ss].l].sum;
    int mid = (l + r) >> 1;
    if (k <= d) return query(tr[ss].l, tr[bs].l, k, l, mid);
    else return query(tr[ss].r, tr[bs].r, k-d, mid + 1, r);
}
int queryK(int ss, int bs, int k, int l, int r) {
    if (l == r) return tr[bs].sum - tr[ss].sum;
    int mid = (l + r) >> 1;
    if (k <= mid) return queryK(tr[ss].l, tr[bs].l, k, l, mid);
    else return queryK(tr[ss].r, tr[bs].r, k, mid+1, r) + tr[tr[bs].l].sum - tr[tr[ss].l].sum;
}
// End ZhuXiShu
int sum[maxn];
int n, total;
void add(int x, int val) {
    for (; x <= total; x += lowbit(x)) sum[x] += val;
}
int getSum(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += sum[x];
    return ans;
}
int blg[maxn];
int da[maxn], ranks[maxn];
pii pda[maxn];
int f[250][maxn];
int queryAns(int l, int r) {
    int ans = 0;
    if (blg[l] == blg[r]) {
        memset(sum, 0, sizeof(sum));
        for (int i = l; i <= r; i++) {
            ans += getSum(total) - getSum(ranks[i]);
            add(ranks[i], 1);
        }
        return ans;
    }
    ans += f[blg[l]+1][r];
    for (int i = l; i <= blg[l] * bls; i++) ans += queryK(root[i], root[r], ranks[i] - 1, 1, total);
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n); bls = sqrt(n);
    for (int i = 1; i <= n; i++) blg[i] = (i - 1) / bls + 1;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a); 
        pda[i].first = a; da[i] = a; pda[i].second = i;
    }

    // ZhuXiShu insert
    sort(pda + 1, pda + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (pda[i].first != pda[i-1].first) total++;
        ranks[pda[i].second] = total;
    }
    tr[0].sum = tr[0].l = tr[0].r = 0;
    for (int i = 1; i <= n; i++) {
        ins(ranks[i], root[i]=root[i-1], 1, total);
    }
    // End ZhuXiShu insert
    for (int i = 1; i <= blg[n]; i++) {
        memset(sum, 0, sizeof(sum));
        for (int j = (i - 1) * bls + 1; j <= n; j++) {
            f[i][j] = f[i][j-1] + getSum(total) - getSum(ranks[j]);
            add(ranks[j], 1);
        }
    }
    int m, ans = 0; scanf("%d", &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        a ^= ans, b ^= ans;
        ans = queryAns(a, b);
        printf("%d\n", ans);
    }
    return 0;
}