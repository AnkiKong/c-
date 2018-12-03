#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=37e4;
bool vis[9][maxn];
int fac[12];
struct rec {
    int pre;
    char op;
    rec() : pre(-1) {}
}record[9][maxn];
void init() {
    fac[0] = 1;
    for (int i = 1; i < 12; i++) fac[i] = fac[i - 1] * i;
}
int kt(int *st) {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        int tmp = 0;
        for (int j = i + 1; j < 9; j++) {
            if (st[i] > st[j]) tmp++;
        }
        ans += tmp * fac[8 - i];
    }
    return ans + 1;
}

struct node {
    int loc;
    int state[10];
};
node startN;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char decs[10] = "drul";
void deal(char *start) {
    int state[20];
    for (int i = 0; i < 9; i++) {
        if (start[i] == 'X') state[0] = 0;
        else state[i] = start[i] - '0';
    }
    memcpy(startN.state, state, sizeof(state));
}
void bfs(int loc) {
    queue<node> q;
    startN.loc = loc;
    q.push(startN);
    node tmp, newN;
    int startKt = kt(startN.state);
    vis[loc][startKt] = 1;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
        int oldKt = kt(tmp.state);
        int x = tmp.loc / 3, y = tmp.loc % 3; 
        for (int i = 0; i < 4; i++) {
            newN = tmp;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            newN.loc = nx * 3 + ny;
            swap(newN.state[tmp.loc], newN.state[newN.loc]);
            int newStKt = kt(newN.state);
            if (vis[loc][newStKt]) continue;
            vis[loc][newStKt] = 1;
            record[loc][newStKt].pre = oldKt;
            record[loc][newStKt].op = decs[i];
            q.push(newN);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    char startStr[12] = "X12345678";
    for (int i = 0; i < 9; i++) {
        deal(startStr);
        bfs(i);
        swap(startStr[i], startStr[i + 1]);
    }
    int T; scanf("%d", &T);
    char str1[20], str2[20];
    int mp[20], state[20];
    for (int TT = 1; TT <= T; TT++) {
        scanf("%s%s", str1, str2);
        int lloc;
        for (int i = 0, cnt = 1; i < 9; i++) {
            if (str1[i] == 'X') lloc = i;
            else mp[str1[i] - '0'] = cnt++;
        }
        for (int i = 0; i < 9; i++) {
            if (str2[i] == 'X') state[i] = 0;
            else state[i] = mp[str2[i] - '0'];
        }
        int nowKt = kt(state);
        stack<char> ans;
        while (true) {
            if (record[lloc][nowKt].pre == -1) break;
            ans.push(record[lloc][nowKt].op);
            nowKt = record[lloc][nowKt].pre;
        }
        while (!ans.empty()) {
            putchar(ans.top());
            ans.pop();
        }
        putchar('\n');
    }
    return 0;
}