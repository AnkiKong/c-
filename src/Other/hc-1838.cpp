#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=3e5+100;
struct node {
    int a, b, id;
    bool operator < (const node& tmp) const {
        return a < tmp.a;
    }
    void ins(int d) {
        scanf("%d%d", &a, &b);
        id = d;
    }
};
node da[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= 2*n+1; i++) {
        da[i].ins(i);
    }
    sort(da+1, da+2*n+2);
    queue<int> ans;
    for (int i = 1; i <=2*n; i+=2) {
        printf("%d\n", da[i].b > da[i+1].b ? da[i].id : da[i+1].id);
    }
    printf("%d", da[2*n+1].id);
    return 0;
}