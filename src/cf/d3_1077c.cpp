#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=2e5 + 100;
ll da[maxn];
map<ll, int> vis;
vector<int> ans;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", da + i);
        sum += da[i]; vis[da[i]] ++;
    }
    for (int i = 0; i < n; i++) {
        vis[da[i]] --;
        if (!((sum-da[i]) & 1) && vis.find((sum-da[i]) / 2) != vis.end() && vis[(sum-da[i]) / 2] != 0) ans.push_back(i + 1);
        vis[da[i]] ++;
    }
    printf("%d\n", ans.size());
    for (auto a : ans) {
        printf("%d ", a);
    }
    return 0;
}