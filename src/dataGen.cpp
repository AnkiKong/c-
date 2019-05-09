#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e3+10;
const int mod=1e3;
int da[mod];
int fa[maxn];
void init(int a) {
    for (int i=0; i<maxn; i++) fa[i]=i;
}
int fin(int a) {
    if (a!=fa[a]) return fa[a]=fin(fa[a]);
    return a;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
#endif
    IOS;
    srand(time(0));
    int n=100000, m=200;
    cout << n << endl;
    for (int i=1; i<=n; i++) {
        cout << rand() << " ";
    }
    cout << endl;
    for (int i=1; i<n; i++) {
        cout << rand() << " ";
    }
    cout << endl;
    cout << m << endl;
    for (; m--; ) {
        int op=rand()&1;
        if (op) cout << "+ ";
        else cout << "s ";
        int l=rand()%n+1, r=rand()%n+1;
        if (l>r) swap(l, r);
        cout << l << ' ' << r << endl;
    }
    return 0;
}