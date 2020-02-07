#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5;
char str[maxn];
int nxt[maxn];
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
    while (~scanf("%s", str)) {
        int len = strlen(str);
        str[len++] = 1;
        scanf("%s", str + len);
        len = strlen(str);
        getNxt();
        if (nxt[len-1] != -1) printf("%s %d\n", str + (len - nxt[len-1] - 1), nxt[len-1] + 1);
        else printf("0\n");
    }
    return 0;
}