#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=14e4;
int loc[maxn];
int sum[maxn];
int n;
inline int lowbit(int a) {return -a & a;}
inline void add(int a, int val) {
    while (a <= n * 2) {
        sum[a] += val;
        a += lowbit(a);
    }
}
inline int cal(int a) {
    int ans = 0;
    while (a) {
        ans += sum[a];
        a -= lowbit(a);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1, a; i <= n * 2; i++) {
        scanf("%d", &a);
        if (loc[a]) {
            ans += cal(i) - cal(loc[a]);
            add(loc[a], -1);
        } else {
            add(i, 1);
            loc[a] = i;
        }
    }
    printf("%d", ans);
    return 0;
}