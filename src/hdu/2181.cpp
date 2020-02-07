#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
set<int> mp[30];
bool vis[30];
int route[30];
int ccnt;
int a, b, c;
void dfs(int u, int cnt) {
    if (cnt == 21) {
        if (route[20] == a) {
            printf("%d: ", ccnt++);
            for (int i = 0; i <= 20; i++) {
                printf(" %d", route[i]);
            }
            printf("\n");
            return ;
        }
        return;
    }
    for (auto aa : mp[u]) {
        if (!vis[aa]) {
            vis[aa] = 1;
            route[cnt] = aa;
            dfs(aa, cnt+1);
            vis[aa] = 0; 
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    for (int i = 1; i <= 20; i++) {
        scanf("%d%d%d", &a, &b, &c);
        mp[i].insert(a);
        mp[i].insert(b);
        mp[i].insert(c);
    }
    while (scanf("%d", &a), a) {
        memset(vis, 0, sizeof(vis));
        ccnt = 1;
        route[0] = a;
        dfs(a, 1);
    }
    return 0;
}