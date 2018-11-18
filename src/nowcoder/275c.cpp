#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5 + 100;
int tr[maxn << 2][25];
int flag[maxn];
void pushUp(int rt) {
    for (int i = 0; i < 20; i++) {
        
    }
}
void build (int l, int r, int rt) {
    if (l == r) {
        int x;
        scanf("%d", &x);
        for (int i = 0; x >> i; i++) {
            if ((x >> i) & 1) tr[rt][i] = 1;
        }

    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    return 0;
}