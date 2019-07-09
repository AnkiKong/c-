#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
#endif
    IOS;
    srand(time(0));
    int cnt=400;
    for (int i=0; i<cnt; i++) {
        int type = rand()%4;
        if (type<2) {
            cout << rand()%500 << endl;
        } else if (type == 2) {
            cout << 500 + rand()%500 << endl;
        } else {
            cout << 1000 + rand()%500 << endl;
        }
    }
    return 0;
}