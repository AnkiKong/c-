#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+100;
int nxt[maxn];
char str[maxn];
bool vis[maxn];
int len;
void getNxt() {
    int k = -1; nxt[0] = -1;
    len = strlen(str);
    for (int i = 1; i < len; i++) {
        while (k != -1 && str[i] != str[k+1]) k = nxt[k];
        if (str[k+1] == str[i]) k++;
        nxt[i] = k;
        if (i != len - 1) vis[k] = 1;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    getNxt();
    for (int i = nxt[len-1]; ~i; i = nxt[i]) {
        if (vis[i]) {
            printf("%s", str + len - i - 1);
            return 0;
        }
    }
    puts("Just a legend");
    return 0;
}