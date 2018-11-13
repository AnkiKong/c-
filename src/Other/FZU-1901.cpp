#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
char str[maxn];
int nxt[maxn];
int ans[maxn];
void getNxt() {
    int k = -1; nxt[0] = -1;
    for (int i = 1; str[i]; i++) {
        while (k != -1 && str[k + 1] != str[i]) k = nxt[k];
        if (str[k + 1] == str[i]) k++;
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
        scanf("%s", str);
        getNxt();
        int len = strlen(str);
        int cnt = 0, k = nxt[len-1];
        while (k != -1) {
            ans[cnt++] = len - k - 1;
            k = nxt[k];
        }
        ans[cnt++] = len;
        printf("Case #%d: %d\n", TT, cnt);
        for (int i = 0; i < cnt; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}