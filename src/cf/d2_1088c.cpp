#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=3000;
int da[maxn];
struct node {
    int op, i, x;
};
queue<node> ans;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", da + i);
        da[i] += 1e4;
    }
    printf("%d\n", n + 1);
    printf("%d %d %d\n", 1, n, int(1e4));
    for (int i = 1; i <= n; i++) {
        // ans.push((node){2, i, da[i] - i});
        printf("%d %d %d\n", 2, i, da[i] - i);
    }
    // printf("%u\n", ans.size());
    // while (!ans.empty()) {
    //     node aa = ans.front(); ans.pop();
    //     printf("%d %d %d\n", aa.op, aa.i. aa.x);
    // }
    return 0;
}