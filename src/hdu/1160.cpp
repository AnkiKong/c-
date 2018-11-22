#include <bits/stdc++.h>
#define pii pair<int, int>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=2000;
struct node {
    int w, s, id;
}da[maxn];
int dp[maxn];
int last[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b;
    int cnt = 0;
    while (~scanf("%d%d", &a, &b)) {
        da[cnt] = (node){a, b, cnt};
        cnt++;
    }
    sort(da, da + cnt, [](node aa, node bb) {return aa.w < bb.w; });
    // for (int i = 0; i < cnt; i++) cout << da[i].first << " " << da[i].second <<endl;
    int mx = 0, loc;
    last[0] = -1;
    for (int i = 1; i < cnt; i++) {
        int mm = 0, la = -1;
        for (int j = 0; j < i; j++) {
            if (da[i].w > da[j].w && da[i].s < da[j].s) {
                // mm = max(mm, dp[j]);
                if (mm < dp[j]) mm = dp[j], la = j;
            }
        }
        dp[i] = mm + 1;last[i] = la;
        if (dp[i] > mx) mx = dp[i], loc = i;
    }
    stack<int> aans;
    while (loc != -1) {
        aans.push(da[loc].id);
        loc = last[loc];
    }
    printf("%u\n", aans.size());
    while (!aans.empty()) {
        printf("%d\n", aans.top() + 1);
        aans.pop();
    }
    return 0;
}