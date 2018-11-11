#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
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
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int len, kase = 1;
    while (scanf("%d", &len) && len) {
        scanf("%s", str); printf("Test case #%d\n", kase++);
        getNxt();
        int tlen, tim;
        for (int i = 1; i < len; i++) {
            if (nxt[i] == -1) continue;
            tlen = i - nxt[i];
            if ((i + 1) % tlen) continue;
            tim = (i + 1) / tlen;
            if (tim * tlen == i + 1) {
                printf("%d %d\n", i + 1, tim);
            }
        }
        printf("\n");
    }
    return 0;
}