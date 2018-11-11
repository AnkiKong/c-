#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
char str[maxn];
int nxt[maxn];
int getNext() {
    int k = -1;nxt[0] = -1;
    for (int i = 1; str[i]; i++) {
        while (k != -1 && str[i] != str[k + 1]) k = nxt[k];
        if (str[k + 1] == str[i]) k++;
        nxt[i] = k;
    }
    int len = strlen(str);
    return len - nxt[len-1] - 1;
}
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%s", str)) {
        printf("%d\n", getNext());
    }
    return 0;
}