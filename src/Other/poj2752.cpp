#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+100;
int nxt[maxn];
int ans[maxn];
char str[maxn];
void getNxt() {
    int k = -1; nxt[0] = -1;
    for (int i = 1; str[i]; i++) {
        while (k != -1 && str[i] != str[k + 1]) k = nxt[k];
        if (str[k + 1] == str[i]) k++;
        nxt[i] = k;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%s", str)) {
        getNxt();
        int cnt = 0;
        int k = strlen(str) - 1;
        ans[cnt++] = k + 1;
        while (k > -1) {
            if (nxt[k] >= 0)
                ans[cnt++] = nxt[k] + 1;
            k = nxt[k];
        }
        for (int i = cnt - 1; i >= 0; i--) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}