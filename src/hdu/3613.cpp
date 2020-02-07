#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+100;
char str1[maxn];
char str2[maxn << 1];
int ma[maxn<<1];
int sum[maxn<<1];
int mp[300];
int len;
int man() {
    int l = 0;
    str2[l++] = '$';
    str2[l++] = '#';
    for (int i = 0; str1[i]; i++) {
        str2[l++] = str1[i];
        str2[l++] = '#';
    }
    str2[l] = 0;
    int mx = 0, id = 0;
    for (int i = 0; i < l; i++) {
        ma[i] = mx > i ? min(ma[2*id-i], mx - i) : 1;
        while (str2[i+ma[i]] == str2[i-ma[i]]) ma[i]++;
        if (i + ma[i] > mx) {
            mx = i + ma[i];
            id = i;
        }
    }
    return l;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        for (int i = 0; i < 26; i++) {
            scanf("%d", mp + i + 'a');
        }
        scanf("%s", str1);
        len = strlen(str1);
        int l = man();
        int ans = 0;
        sum[1] = 0;
        for (int i = 3; i < l; i += 2) {
            sum[i] = sum[i - 2] + mp[int(str2[i - 1])];
        }
        for (int i = 3; i < l - 1; i += 2) {
            int mid1 = (1 + i) >> 1;
            int mid2 = (i + l - 1) >> 1;
            int tmp = 0;
            bool flag1 = 0, flag2 = 0;
            if (ma[mid1] >= i - mid1 + 1) {
                // for (int j = 2; j <= i; j += 2) tmp += mp[str2[j]];
                // flag1 = 1;
                tmp += sum[i];
            }
            if (ma[mid2] >= mid2 - i + 1) {
                // for (int j = i + 1; j < l; j += 2) tmp += mp[str2[j]];
                // flag2 = 1;
                tmp += sum[l - 1] - sum[i];
            }
            ans = max(ans, tmp);
            if (flag1 && flag2) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}