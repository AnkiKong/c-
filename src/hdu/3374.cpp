#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6 + 100;
char str[maxn];
int nxt[maxn];
int len;
void getNxt() {
    int k = -1; nxt[0] = -1;
    for (int i = 1; i < len; i++) {
        while (k != -1 && str[i] != str[k + 1]) k = nxt[k];
        if (str[k + 1] == str[i]) k++;
        nxt[i] = k;
    }
}
int min_max_exp(int len, bool flag) {
    // flag: true min_exp, false max_exp
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = str[(j + k) % len] - str[(i + k) % len];
        if (t == 0) k++;
        else {
            if (flag) {
                if (t > 0) j += k + 1;
                else i += k + 1;
            } else {
                if (t > 0) i += k + 1;
                else j += k + 1;
            }
            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%s", str)) {
        len = strlen(str);
        int min_exp = min_max_exp(len, true);
        int max_exp = min_max_exp(len, false);
        getNxt();
        int l = len - nxt[len-1] - 1;
        int ans = len % l ? 1 : len / l;
        printf("%d %d %d %d\n", min_exp + 1, ans, max_exp + 1, ans);
    }
    return 0;
}