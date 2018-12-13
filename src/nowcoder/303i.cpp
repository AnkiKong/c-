#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1100;
struct node {
    char name;
    int id, type;
    bool operator < (const node& aaa) const {
        return type < aaa.type;
    }
};
node da[maxn];
int mp[256];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    char str1[50], str2[10];
    for (int TT = 1; TT <= T; TT++) {
        int n, iid; scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%s%s", &iid, str1, str2);
            da[i] = (node){str2[0], iid, 0};
        }
        scanf("%s", str1);
        mp[str1[0]] = 1;
        int pos = 2;
        for (int i = 1; str1[i]; i++) {
            if (str1[i] == ',') mp[str1[i + 1]] = pos++;
        }
        for (int i = 0; i < n; i++) da[i].type = mp[da[i].name];
        stable_sort(da, da+n);
        for (int i = 0; i < n; i++) {
            printf("%d%c", da[i].id, i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}