#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=2e5 + 100;
int da[maxn];
int n, k; 
int check(int tim) {
    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        cnt += da[i] / tim;
    }
    return cnt;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int tmp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        da[tmp] ++;
    }
    int l = 1, r = n + 1, ti=1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid) >= k) l = mid + 1, ti = mid;
        else r = mid;
    }
    // printf("%d\n", ti);
    for (int i = 0; i < maxn && k; i++) {
        tmp = da[i] / ti;
        for (int j = 0; j < tmp && k; j++) {
            printf("%d ", i);k--;
        }
    }

    return 0;
}