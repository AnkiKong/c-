#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
map<string, int> st[60];
string str[60];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    int len = str[0].length();
    for (int i = 0; i < n; i++) {
        string tmp = str[i];
        st[i][tmp] = 0;
        for (int j = 1; j < len; j++) {
            tmp = tmp.substr(1, len) + tmp.substr(0, 1);
            if (st[i].count(tmp)) continue;
            st[i][tmp] = j;
        }
    }
    int ans = 0x3f3f3f3f, lans;
    string tmp = str[0];
    for (int i = 0; i < len; i++) {
        lans = 0;
        tmp = tmp.substr(1, len) + tmp.substr(0, 1);
        for (int j = 0; j < n; j++) {
            if(st[j].count(tmp)) lans += st[j][tmp];
            else {
                cout << -1 << endl; return 0;
            }
        }
        ans = min(ans, lans);
    }
    cout << ans << endl;
    return 0;
}