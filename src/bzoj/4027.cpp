#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e6 + 100;
vector<int> son[maxn];
int c[maxn], cost[maxn];
int sonCnt[maxn];
int n, m, ans;
int cmp(int a, int b) {
    return cost[a] < cost[b];
}
void dfs(int u) {
    int son_Cnt = sonCnt[u];
    cost[u] = c[u] + son_Cnt;
    if (sonCnt[u] == 0) return;
    for (int i = 0; i < son_Cnt; i++) dfs(son[u][i]);
    sort(son[u].begin(), son[u].end(), cmp);
    for (int i = 0; i < son_Cnt; i++) {
        int a = son[u][i];
        if (cost[a] + cost[u] - 1 > m) break;
        ans++, cost[u] += cost[a] - 1; 
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", c + i);
    }
    for (int i = 0, cnt, tmp; i < n; i++) {
        scanf("%d", &cnt);
        sonCnt[i] = cnt;
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &tmp);
            son[i].push_back(tmp);
        }
    }
    dfs(0);
    printf("%d", ans);
    return 0;
}