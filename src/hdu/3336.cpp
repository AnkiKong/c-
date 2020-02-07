#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200000 + 1000;
char str[maxn];
int nxt[maxn];
int sum[maxn];
void getNxt() {
    int k = -1;
    nxt[0] = -1;
    for (int i = 1; str[i]; i++) {
        while (k != -1 && str[i] != str[k + 1]) k = nxt[k];
        if (str[i] == str[k + 1]) k++;
        nxt[i] = k;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int len; scanf("%d%s", &len, str);
        getNxt();
        int ans = 0;
        for (int i = 0; i < len; i++) sum[i] = 1;
        for (int i = len - 1; i >= 0; i--) {
            if (nxt[i] != -1) sum[nxt[i]] = (sum[nxt[i]] + sum[i]) %10007;
            ans= (ans + sum[i]) % 10007;
        }
        printf("%d\n", ans);
    }
    return 0;
}