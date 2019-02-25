// #include <bits/stdc++.h>
// #ifndef LOCAL
// #pragma GCC optimize(3)
// #endif
// using namespace std;
// typedef long long ll;
// const int inf=0x3f3f3f3f;
// const int maxn=110;
// const int maxm = 2e5;
// struct node {
//     int u, w, nxt;
// }v[maxm];
// int head[maxm], cnt;
// int start = 0, stop = 1e5;
// void add(int a, int b, int c) {
//     v[cnt] = (node) {b, c, head[a]}; head[a] = cnt++;
// }
// int g[maxn][maxn];
// int idd[maxn][maxn];
// int n, m;

// int gap[maxm], dep[maxm];
// void bfs() {
//     memset(dep, -1, sizeof(dep));
//     dep[stop] = 0; gap[0] = 1; 
//     queue<int> q; q.push(stop);
//     while (!q.empty()) {
//         int now = q.front(); q.pop();
//         for (int to, i = head[now]; ~i; i = v[i].nxt) {
//             to = v[i].u;
//             if (dep[to] != -1) continue;
//             dep[to] = dep[now] + 1; gap[dep[to]]++;
//             q.push(to);
//         }
//     }
// }
// int c = 1;
// int cur[maxm], s[maxm];
// int sap() {
//     bfs();
//     if (dep[start] == -1) return 0;
//     memcpy(cur, head, sizeof(head));
//     int u = start, ans = 0, top = 0;
//     c += 2;
//     while(dep[start] < c) {
//         if (u == stop) {
//             int flow = inf, inser;
//             for (int i = 0; i < top; i++) {
//                 if (flow > v[s[i]].w) {
//                     flow = v[s[i]].w, inser = i;
//                 }
//             }
//             for (int i = 0; i < top; i++) {
//                 v[s[i]].w -= flow;
//                 v[s[i]^1].w += flow;
//             }
//             ans += flow; top = inser, u = v[s[top]^1].u;
//             continue;
//         }
//         bool flag = false;
//         int t;
//         for (int i = cur[u]; ~i; i = v[i].nxt) {
//             t = v[i].u;
//             if (v[i].w && dep[t] + 1 == dep[u]) {
//                 flag = true; cur[u] = i; break;
//             }
//         }
//         if (flag) {
//             s[top++] = cur[u], u = t; continue;
//         }
//         int Min = c;
//         for (int i = head[u]; ~i; i = v[i].nxt) {
//             if (v[i].w && dep[v[i].u] + 1 < Min) {
//                 Min = dep[v[i].u]; cur[u] = i;
//             }
//         }
//         gap[dep[u]]--;
//         if (!gap[dep[u]]) return ans;
//         dep[u] = Min + 1;
//         gap[dep[u]]++;
//         if (u != start) u = v[s[--top]^1].u;
//     }
//     return ans;
// }
// int main() {
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     memset(head, -1, sizeof(head));
//     // memset(g, -1, sizeof(g));
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             scanf("%d", g[i] + j); idd[i][j] = c++;
//         }
//     }
//     int dx[] = {0, 1, 0, -1};
//     int dy[] = {1, 0, -1, 0};
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             int now = idd[i][j];
//             if (g[i][j] == 2) {
//                 add(start, now, inf);
//                 add(now, start, 0);
//                 for (int k = 0; k < 4; k++) {
//                     int nx = i + dx[k], ny = j + dy[k];
//                     if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
//                     if (g[nx][ny] != 2) {
//                         add(now, idd[nx][ny], 1);
//                         add(idd[nx][ny], now, 0);
//                     }
//                 }
//             } else if (g[i][j] == 1) {
//                 add(now, stop, inf);
//                 add(stop, now, 0);
//             } else {
//                 for (int k = 0; k < 4; k++) {
//                     int nx = i + dx[k], ny = j + dy[k];
//                     if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
//                     if (g[nx][ny] == 2) continue;
//                     add(now, idd[nx][ny], 1);
//                     add(idd[nx][ny], now, 0);
//                 }
//             }
//         }
//     }
//     printf("%d\n", sap());
//     return 0;
// }