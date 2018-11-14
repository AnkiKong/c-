#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
char str[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // char str[10000];
    int len, n; scanf("%d%d", &len, &n);
    scanf("%s", str);
    int l = 0, need = n / 2;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            if (l < need) {
                putchar('(');
                l++;
            }
        } else {
            if (l) {
                putchar(')');l--;need--;
            }
        }
    }
    return 0;
}