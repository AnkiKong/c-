#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=37e4;
bool vis[maxn];
int st[10];
int fac[15];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char decs[10] = "drul";
struct paths {
    int pre;
    char op;
} record[maxn];
void print(int now) {
    if (record[now].pre == -1) return;
    print(record[now].pre);
    putchar(record[now].op);
}
void init() {
    fac[0] = 1;
    for (int i = 1; i < 15; i++)fac[i] = fac[i-1] * i;
}
int check() {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        if (st[i] == 0) continue;
        int tmp = 0;
        for (int j = i + 1; j < 9; j++) {
            if (st[j] == 0) continue;
            if (st[i] < st[j]) tmp++;
        }
        ans += tmp;
    }
    return ans & 1;
}
int cantor(int *st) {
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
int getH(int *st) {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        if (!st[i]) continue;
        int x = (st[i] - 1) / 3, y = (st[i] - 1) % 3;
        ans += abs(x - i / 3) + abs(y - i % 3);
    }
    return ans;
}
struct node {
    int state[10];
    int h, g, loc;
    bool operator < (const node &tmp) const {
        return h + g > tmp.h + tmp.g;
        // if (h != tmp.h) return h > tmp.h;
        // else return g > tmp.g;
    }
};
int a_star() {
    priority_queue<node> q;
    node tmp;
    for (int i = 0; i < 9; i++) {
        tmp.state[i] = st[i];
        if (!st[i]) tmp.loc = i;
    }
    int endd[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int endst = cantor(endd);
    tmp.g = 0; tmp.h = getH(st);
    q.push(tmp);
    int start = cantor(st);
    record[start].pre = -1;
    vis[start] = 1;
    while (!q.empty()) {
        tmp = q.top(); q.pop();
        int nowst = cantor(tmp.state);
        if (nowst == endst) {
            print(nowst);
            putchar('\n');
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            node newst = tmp;
            int x = tmp.loc / 3, y = tmp.loc % 3;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2) {
                continue;
            }
            swap(newst.state[tmp.loc], newst.state[nx * 3 + ny]);
            int newstCt = cantor(newst.state);
            if (vis[newstCt]) continue;
            vis[newstCt] = 1;
            record[newstCt].pre = nowst;
            record[newstCt].op = decs[i];
            newst.loc = nx * 3 + ny;
            // char ttt = decs[i];
            // newst.path = newst.path + ttt;
            newst.h = getH(newst.state);
            newst.g = tmp.g + 1;
            q.push(newst);
        }
        
    }
    return 1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    char tt[10];
    while (true) {
        for (int i = 0; i < 9; i++) {
            if (scanf("%s", tt) == EOF) return 0;
            if (tt[0] == 'x') st[i] = 0;
            else st[i] = tt[0] - '0';
        }
        memset(vis, 0, sizeof(vis));
        if (check()) {
            printf("unsolvable\n");
        } else {
            if (a_star()) {
                printf("unsolvable\n");
            }
        }
    }
    return 0;
}