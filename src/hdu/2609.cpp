#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200;
char str[maxn];
char str2[maxn];
vector<string> data;

int min_max_exp(int len, bool flag) {
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = str[(j + k) % len] - str[(i + k) % len];
        if (t == 0) k++;
        else {
            if (flag) {
                if (t > 0) j += k + 1;
                else i += k + 1;
            } else {
                if (t > 0) i += k + 1;
                else j += k + 1;
            }
            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n)) {
        data.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            int len = strlen(str);
            int k = min_max_exp(len, true);
            for (int j = 0; j < len; j++) {
                str2[j] = str[(k + j) % len];
            }
            str2[len] = 0;
            data.push_back(string(str2));
        }
        sort(data.begin(), data.end());
        printf("%u\n", unique(data.begin(), data.end()) - data.begin());
    }
    return 0;
}