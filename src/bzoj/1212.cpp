#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=(1 << 20) + 100;
int tr[int(1e5)][26];
int ed[int(1e5)];
int dp[maxn];
char str[maxn], str2[20], cnt=1;
void add() {
    int len = strlen(str2);
    int now = 0, tmp;
    for (int i = 0; i < len; i++) {
        tmp = str2[i] - 'a';
        if (tr[now][tmp] == 0) tr[now][tmp] = cnt++;
        now = tr[now][tmp];
    }
    ed[now] = 1;
}
int func(int t) {
    dp[0] = t;
    int ans = 0;
    int len = strlen(str + 1);
    for (int i = 0; i <= len; i++) {
        if (dp[i] != t) continue;
        else ans = i;
        for (int j = i + 1, now = 0; str[j]; j++) {
            now = tr[now][str[j] - 'a'];
            if (!now) break;
            if (ed[now]) dp[j] = t;
        }
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str2);
        add();
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", str + 1);
        printf("%d\n", func(i));
    }
    return 0;
}