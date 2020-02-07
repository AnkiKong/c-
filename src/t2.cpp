#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6;
char s[maxn], k[maxn];
int nxt[maxn];

void getNxt() {
    int m=-1; nxt[0]=-1;
    int len=strlen(k);
    for (int i=1; i<len; i++) {
        while (m>-1 && k[i]!=k[m+1]) m=nxt[m];
        if (k[i]==k[m+1]) m++;
        nxt[i]=m;
    }
}

bool kmp() {
    getNxt();
    int slen=strlen(s), klen=strlen(k);
    int m=-1;
    for (int i=0; i<slen; i++) {
        while (m>-1 && s[i]!=k[m+1]) m=nxt[m];
        if (s[i]==k[m+1]) m++;
        if (m>=klen-1) return true;
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s", s, k);
    printf("%s", kmp() ? "Yes" : "No");
    return 0;
}