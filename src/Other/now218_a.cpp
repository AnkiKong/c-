#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn=1e6 + 100;
char str[maxn];
char vis[maxn];
int n, m;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int check(int x, int y, int viss) {
    if (x < n && y < m && x >= 0 && y >= 0) {
        if (str[x*m+y] == '#' || vis[x*m+y] == viss) return 0;
        else return 1;
    }
    return -1;
}
void bfs(int loc) {
    int x = loc / m, y = loc % m;
    vis[loc] = 1;
    queue< pii > q;
    q.push(make_pair(x, y));
    int act = 0;
    while (!q.empty()) {
        pii tmp = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tmp.first + dx[i];
            int ny = tmp.second + dy[i];
            int res = check(nx, ny, 1);
            if (res == 1) {
                q.push(make_pair(nx, ny));
                vis[nx * m + ny] = 1;
            } else if (res == -1) {
                act = -1;
                break;
            }
        }
    }
    char fills;
    if (act == 0) fills = '@';
    else fills = '%';
    q.push(make_pair(x, y));
    vis[loc] = 2;
    while (!q.empty()){
        pii tmp = q.front(); q.pop();
        // vis[tmp.first * m + tmp.second] = 2;
        str[tmp.first * m + tmp.second] = fills;
        for (int i = 0; i < 4; i++) {
            int nx = tmp.first + dx[i];
            int ny = tmp.second + dy[i];
            int res = check(nx, ny, 2);
            if (res == 1) {
                q.push(make_pair(nx, ny));
                vis[nx * m + ny] = 2;
                // str[nx * m + ny] = fills;
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    scanf("%d%d", &n, &m);
    for (int i = 0, j = 0; i < n; i++, j += m) {
        scanf("%s", str + j);
    }
    int sum = n * m;
    for (int i = 0; i < sum; i++) {
        if (str[i] == '.') {
            bfs(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i * m + j] == '%');
            else ans++;
        }
        // putchar('\n');
    }
    printf("%d\n", ans);
    return 0;
}