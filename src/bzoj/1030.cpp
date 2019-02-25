// #include <bits/stdc++.h>
// #ifndef LOCAL
// #pragma GCC optimize(3)
// #endif
// using namespace std;
// typedef long long ll;
// const int inf=0x3f3f3f3f;
// const int maxn=1e4;
// char str[maxn];
// int n, m;
// const int mod = 10007;
// int sub;
// struct ac{
//     int tr[maxn][26], ed[maxn], fail[maxn];
//     int dp[1100][maxn];
//     int cnt;
//     void init() {
//         // memset(tr[0], -1, sizeof(tr[0]));
//         cnt = 2;
//     }
//     int newNode() {
//         // memset(tr[cnt], -1, sizeof(tr[cnt]));
//         return cnt++;
//     }
//     void add() {
//         int now = 1;
//         for (int i = 0; str[i]; i++) {
//             int tmp = str[i] - 'A';
//             if (tr[now][tmp] == 0) tr[now][tmp] = newNode();
//             now = tr[now][tmp];
//         }
//         ed[now] = 1;
//     }
//     void makeFail() {
//         queue<int> q;
//         q.push(1);
//         while (!q.empty()) {
//             int tmp = q.front(); q.pop();
//             for (int i = 0; i < 26; i++) {
//                 if (!tr[tmp][i]) {
//                     fail[tr[tmp][i]] = tr[fail[tmp]][i];
//                 } else {
//                     tr[tmp][i] = tr[fail[tmp]][i];
//                     q.push(tr[tmp][i]);
//                 }
//             }
//         }
//     }
//     void solve() {
//         dp[0][1] = 1;
//         for (int i = 0; i < m; i++) {
//             for (int j = 2; j < cnt; j++) {
//                 for (int k = 0; k < 26; k++) {
//                     int now = j;
//                     bool flag = 0;
//                     while (now) {
//                         if (ed[tr[now][k]]) {
//                             flag = 1; break;
//                         }
//                         now = fail[now];
//                     }
//                     if (flag) continue;
//                     now = j;
//                     while (!tr[now][k]) 
//                         now = fail[now];
//                     now = tr[now][k];
//                     dp[i+1][now] = (dp[i+1][now] + dp[i][j]) % mod;
//                 }
//             }
//         }
//         for (int i = 0; i < cnt; i++) {
//             sub = (sub + dp[m][cnt]) % mod;
//         }
//     }
// };
// ac data;
// int main() {
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     data.init();
//     scanf("%d%d", &n, &m);
//     for (int i = 0; i < n; i++) {
//         scanf("%s", str);
//         data.add();
//     }
//     data.makeFail();
//     data.solve();
//     int ans = 1;
//     for (int i = 0; i < m; i++) ans = ans * 26 % mod;
//     printf("%d\n", (ans - sub + mod) % mod);
//     return 0;
// }