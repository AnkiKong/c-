#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int da[maxn];
int sum[maxn];
int dp[maxn];
int que[maxn];
int head, tot;
int n, m;
int _2(int a) {
    return a*a;
}
int cal(int i, int j) {
    return dp[j] + _2(sum[i] - sum[j]) + m;
}
int son(int i, int j) {
    return (dp[j]+_2(sum[j])) - (dp[i]+_2(sum[i]));
}
int pare(int i, int j) {
    return 2 * (sum[j] - sum[i]);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m)) {
        memset(dp, 0, sizeof(dp));
        head = tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", da+i);
            sum[i] = sum[i-1] + da[i];
        }
        que[tot++] = 0;
        for (int i = 1; i <= n; i++) {
            while (head+1<tot && son(que[head], que[head+1]) <= sum[i]*pare(que[head], que[head+1])) head++;
            dp[i] = cal(i, que[head]);
            while (head+1<tot && son(que[tot-2], que[tot-1]) * pare(que[tot-1], i) >= son(que[tot-1], i) * pare(que[tot-2], que[tot-1])) tot--;
            que[tot++] = i;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}