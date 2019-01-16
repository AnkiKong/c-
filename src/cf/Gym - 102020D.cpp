#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=2e6+100;
int tr[maxn][10];
int ans[maxn];
int cnt = 1;
int to[300];
char str[maxn];
void init() {
    to['a'] = 2; to['k'] = 5; to['u'] = 8;
    to['b'] = 2; to['l'] = 5; to['v'] = 8;
    to['c'] = 2; to['m'] = 6; to['w'] = 9;
    to['d'] = 3; to['n'] = 6; to['x'] = 9;
    to['e'] = 3; to['o'] = 6; to['y'] = 9;
    to['f'] = 3; to['p'] = 7; to['z'] = 9;
    to['g'] = 4; to['q'] = 7;
    to['h'] = 4; to['r'] = 7;
    to['i'] = 4; to['s'] = 7;
    to['j'] = 5; to['t'] = 8;
}
void add() {
    int now = 1, nxt;
    for (int i = 0; str[i]; i++) {
        nxt = to[(int)str[i]];
        if (tr[now][nxt] == 0) tr[now][nxt] = ++cnt;
        now = tr[now][nxt];
        ans[now]++;
    }
    cnt++;
}
int query() {
    int now = 1, nxt;
    for (int i = 0; str[i]; i++) {
        nxt = str[i] - '0';
        if (tr[now][nxt] == 0) return 0;
        now = tr[now][nxt];
    }
    return ans[now];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int n, m; 
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        add();
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        printf("%d\n", query());
    }
    return 0;
}