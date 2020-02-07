#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
set<int> vis;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        vis.insert(tmp);
    }
    int sub = 0;
    while (m--) {
        if (!vis.size()) printf("0\n");
        else {
            printf("%d\n", *vis.begin() - sub);
            sub = *vis.begin();
            vis.erase(sub);
        }
    }
    return 0;
}