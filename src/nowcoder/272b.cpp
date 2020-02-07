#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=5e5 + 100;
int cnt[maxn];
int a[maxn];
int ans;
list<int> mp[maxn];
int n;

void dfs(int now, int last) {
    int sum = 1, ccnt = 0;
    cnt[now] = 1;
    for (auto aa : mp[now]) {
        if (aa == last) continue;
        dfs(aa, now);
        cnt[now] += cnt[aa];
        ccnt ^= (sum * cnt[aa]) & 1;
        sum += cnt[aa];
    }
    ccnt ^= ((n - sum) * sum) & 1;
    if (ccnt & 1) ans ^= a[now];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int aa, bb;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &aa, &bb);
        mp[aa].push_back(bb);
        mp[bb].push_back(aa);
    }
    int start;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (mp[i].size() == 1) start = i;
    }
    dfs(1, -1);
    printf("%d", ans);
    return 0;
}