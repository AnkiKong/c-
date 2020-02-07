#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn=1010;
vector<pii > mp[maxn];
vector<pii > reMp[maxn];
const int inf = 0x3f3f3f3f;
int len1[maxn], len2[maxn];
int n, m;
int start, stop;
int head[maxn];
struct node {
    int f, to, nxt;
};
node ve[maxn * 200];
int cnt;
void add(int u, int v, int f) {
    ve[cnt] = (node) {f, v, head[u]};
    head[u] = cnt++;
    ve[cnt] = (node) {0, u, head[v]};
    head[v] = cnt++;
}
void dijk(int start, int* llen, vector<pii > mmp[]) {
    struct node {
        int len, a;
        bool operator < (const node &a) const {
            return len > a.len;
        }
    };
    priority_queue<node> q;
    q.push((node){0, start});
    llen[start] = 0;
    while (!q.empty()) {
        node now = q.top(); q.pop();
        for (auto a : mmp[now.a]) {
            if (llen[a.first] > llen[now.a] + a.second) {
                llen[a.first] = llen[now.a] + a.second;
                q.push((node){llen[a.first], a.first});
            }
        }
    }
}
void init(int n) {
    for (int i = 0; i <= n; i++)mp[i].clear(), reMp[i].clear();
    memset(len1, 0x3f3f, sizeof(len1));
    memset(len2, 0x3f3f, sizeof(len2));
    memset(head, -1, sizeof(head));
    cnt = 0;
}
int dep[maxn], gap[maxn];
void bfs() {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1; queue<int> q;
    dep[stop] = 0;
    q.push(stop);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = head[now]; ~i; i = ve[i].nxt) {
            int to = ve[i].to;
            if (dep[to] != -1) continue;
            q.push(to); dep[to] = dep[now] + 1;
            gap[dep[to]]++;
        }
    }
}

int cur[maxn], s[maxn];
int sap() {
    bfs();
    memcpy(cur, head, sizeof(head));
    int u = start, ans = 0, top = 0;
    while (dep[start] < n) {
        if (u == stop) {
            int flow = inf, inser;
            for (int i = 0; i < top; i++) {
                if (flow > ve[s[i]].f) {
                    flow = ve[s[i]].f, inser = i;
                }
            }
            for (int i = 0; i < top; i++) {
                ve[s[i]].f -= flow;
                ve[s[i] ^ 1].f += flow;
            }
            ans += flow; top = inser, u = ve[s[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; ~i; i = ve[i].nxt) {
            v = ve[i].to;
            if (ve[i].f && dep[v] + 1 == dep[u]) {
                flag = true; cur[u] = i; break;
            }
        }
        if (flag) {
            s[top++] = cur[u]; u = v; continue;
        }
        int Min = n;
        for (int i = head[u]; ~i; i = ve[i].nxt) {
            if (ve[i].f && dep[ve[i].to] < Min) {
                Min = dep[ve[i].to]; cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if (!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start) u = ve[s[--top]^1].to;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &n, &m);
        init(n);
        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            mp[a].push_back(make_pair(b, c));
            reMp[b].push_back(make_pair(a, c));
        }
        scanf("%d%d", &start, &stop);
        dijk(start, len1, mp);
        dijk(stop, len2, reMp);
        int mm = len1[stop];
        for (int i = 1; i <= n; i++) {
            for (auto aa : mp[i]) {
                if (len1[i] + len2[aa.first] + aa.second == mm) {
                    add(i, aa.first, 1);
                }
            }
        }
        printf("%d\n", sap());
    }
    return 0;
}