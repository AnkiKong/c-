#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+100;
char str[maxn];
int nxt[maxn];
int len;
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
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        len = strlen(str);
        getNxt();
        int nlen = len - nxt[len-1] - 1;
        printf("%d\n", nlen - (nxt[len-1]) % nlen - 1);
    }
    return 0;
}