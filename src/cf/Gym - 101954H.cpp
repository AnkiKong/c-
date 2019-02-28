#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3000;
int sg[maxn];
int getSg(int n) {
    if (n == 1) return sg[1] = 0;
    if (sg[n] != -1) return sg[n];
    set<int> vis;
    for (int i = 1; i < n; i++) {
        int cnt = n / i, res = n % i;
        if (cnt % 2 == 0) {
            if (res) vis.insert(getSg(res));
            else vis.insert(0);
        } else {
            if (res) 
                vis.insert(getSg(i) ^ getSg(res));
            else
                vis.insert(getSg(i));
        }
    }
    for (int i = 0; ; i++) if (!vis.count(i)) return sg[n] = i;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(sg, -1, sizeof(sg));
    getSg(2000);
    int n, ans = 0; scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        ans ^= sg[a];
    }
    if (ans) printf("First\n");
    else printf("Second\n");
    return 0;
}