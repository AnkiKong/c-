#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=100;
char str[100];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    int l = 0, r = strlen(str) - 1;
    int flag = r & 1;
    stack<char> ans;
    while (l <= r) {
        if (flag) ans.push(str[r--]);
        else ans.push(str[l++]);
        flag ^= 1;
    }
    while (!ans.empty()) {
        putchar(ans.top());
        ans.pop();
    }
    return 0;
}