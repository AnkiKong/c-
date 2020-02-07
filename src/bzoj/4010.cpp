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
const int maxn=1e5+100;
int head[maxn], to[maxn], nxt[maxn], vcnt;
void add(int a, int b) {
    to[++vcnt] = b; nxt[vcnt] = head[a]; head[a] = vcnt;
}
int ind[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1, n, m; TT <= T; TT++) {
        memset(head, 0, sizeof(head)); vcnt = 0;
        memset(ind, 0, sizeof(ind));
        scanf("%d%d", &n, &m);
        for (int i = 0, a, b; i < m; i++) {
            scanf("%d%d", &a, &b);
            add(b, a); ind[a]++;
        }
        stack<int> ans;
        priority_queue<int> q;
        for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
        while(!q.empty()){
            int x = q.top(); q.pop(); ans.push(x);
            for (int i = head[x]; i; i = nxt[i]) {
                ind[to[i]]--;
                if (!ind[to[i]]) q.push(to[i]);
            }
        }
        if (ans.size() == n) {
            while(!ans.empty()){
                printf("%d ", ans.top());
                ans.pop();
            }
        } else {
            printf("Impossible!");
        }
        printf("\n");
    }
    
    return 0;
}