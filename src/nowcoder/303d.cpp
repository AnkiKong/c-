#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii pair<int, int>
using namespace std;
typedef long long ll;
// const int maxn=;
pii da[10];
int ans[10];
int cnt = 0;
int dfs(int st, int res, int level){
    bool flag = 1;
    int aans = 0;
    for (int i = st; i < 7; i++) {
        if (da[i].first <= res) {
            ans[level] = i;
            aans = max(dfs(i + 1, res - da[i].first, level + 1), aans);
            flag = 0;
        }
    }
    if (flag || aans == 0) {
        ll rres = 0;
        for (int i = 0; i < level; i++) {
            rres += da[ans[i]].second - da[ans[i]].first;
        }
        if (rres >= res) {
            return level;
        } else {
            return 0;
        }
    }
    return aans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T, a, b; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int n; scanf("%d", &n);
        for (int i = 0; i < 7; i++) {
            scanf("%d%d", &a, &b);
            da[i] = make_pair(a, b);
        }
        sort(da, da + 7);
        
        int ans = dfs(0, n, 0);
        printf("%d\n", ans);
    }

    return 0;
}