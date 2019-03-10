// #include <bits/stdc++.h>
// #ifndef LOCAL
// #pragma GCC optimize(3)
// #endif
// using namespace std;
// typedef long long ll;
// const int maxn =1010;
// vector<int> r[maxn], l[maxn];
// int da[maxn][maxn];
// int ans[maxn][maxn];
// int main() {
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             scanf("%d", da[i] + j);
//             r[i].push_back(da[i][j]);
//         }
//         sort(r[i].begin(), r[i].end(), less<int>());
//         r[i].erase(unique(r[i].begin(), r[i].end()), r[i].end());
//     }
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) 
//             l[i].push_back(da[j][i]);
//         sort(l[i].begin(), l[i].end(), less<int>());
//         l[i].erase(unique(l[i].begin(), l[i].end()), l[i].end());
//     }
//     int tmp, a, b, is, js;
//     for (int i = 0; i < n; i++) {
//         is = r[i].size();
//         // if (is==1) is--;
//         for (int j = 0; j < m; j++) {
//             tmp = da[i][j];
//             js = l[j].size();
//             // if (js==1&&is) js--;
//             a = lower_bound(r[i].begin(), r[i].end(), tmp) - r[i].begin();
//             b = lower_bound(l[j].begin(), l[j].end(), tmp) - l[j].begin();
//             ans[i][j] = max(a, b) + max(is-a, js-b);
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             printf("%d ", ans[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }