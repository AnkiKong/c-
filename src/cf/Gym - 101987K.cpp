#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e4+100;
vector<int> mp[maxn];
bool vis[maxn];
stack<int> s;
bool dfs(int x) {
    if (vis[x^1]) return false;
    if (vis[x]) return true;
    vis[x]=1; s.push(x);
    for (int t:mp[x]) {
        if (!dfs(t)) return false;
    }
    return true;
}
bool twoSat(int n) {
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<n; i+=2) {
        if (vis[i] || vis[i^1]) continue;
        while (s.size()) s.pop();
        if (!dfs(i)) {
            while (s.size()) vis[s.top()]=false, s.pop();
            if (!dfs(i^1)) return false;
        }
    }
    return true;
}
char s1[10], s2[10], s3[10];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k; scanf("%d%d", &k, &n);
    for (int i=0, a, b, c, _a, _b, _c; i<n; i++) {
        scanf("%d%s%d%s%d%s", &a, s1, &b, s2, &c, s3);
        a--; a<<=1; if (s1[0]=='R') _a=a^1; else _a=a, a^=1;
        b--; b<<=1; if (s2[0]=='R') _b=b^1; else _b=b, b^=1;
        c--; c<<=1; if (s3[0]=='R') _c=c^1; else _c=c, c^=1;
        mp[_a].push_back(b); mp[_a].push_back(c);
        mp[_b].push_back(a); mp[_b].push_back(c);
        mp[_c].push_back(a); mp[_c].push_back(b);
    }
    if (twoSat(k*2)) {
        for (int i=0; i<2*k; i+=2) {
            printf("%c", "BR"[vis[i]]);
        }
    } else {
        puts("-1");
    }
}
// int head[maxn], to[maxn*100], nxt[maxn*100], cnt;
// void add(int a, int b) {
//     to[cnt] = b, nxt[cnt] = head[a]; head[a] = cnt++;
// }

// char ans[maxn];
// int dfn[maxn], low[maxn], vis[maxn], ins[maxn], dfns, Amount;
// int belong[maxn], cnts[maxn];
// stack<int> s;
// void tarjan(int u) {
//     vis[u] = ins[u] = 1; s.push(u);
//     dfn[u] = low[u] = dfns++;
//     for (int i = head[u]; ~i; i = nxt[i]) {
//         if (!vis[to[i]]) tarjan(to[i]), low[u] = min(low[u], low[to[i]]);
//         else if (ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
//     }
//     int x = 0;
//     if (dfn[u] == low[u]) {
//         Amount++;
//         while (x != u) {
//             x = s.top(); s.pop(); ins[x] = 0;
//             belong[x] = Amount; cnts[Amount]++;
//         }
//     }
// }
// int another[maxn], color[maxn], ind[maxn];
// vector<int> mp2[maxn];
// void tp(int n) {
//     for (int i=0; i<=n; i++) mp2[i].clear();
//     memset(color, 0, sizeof(color));
//     for (int i=1; i<=(n<<1); i++) {
//         for (int j=head[i]; ~j; j=nxt[j]) {
//             int t=to[j];
//             if (belong[i]!=belong[t]) {
//                 mp2[belong[t]].push_back(belong[i]);
//                 ind[belong[i]]++;
//             }
//         }
//     }
//     for (int i=1; i<=n; i++) {
//         another[belong[i]]=belong[i+n];
//         another[belong[i+n]]=belong[i];
//     }
//     queue<int> q;
//     for (int i=1; i<=Amount; i++) {
//         if (ind[i]==0) q.push(i);
//     }
//     for (int nw; !q.empty(); q.pop()) {
//         nw=q.front();
//         if (color[nw]==0) {
//             color[nw]='R'; color[another[nw]]='B';
//         }
//         for (int t:mp2[nw]) {
//             if (!(--ind[t])) {
//                 q.push(t);
//             }
//         }
//     }
// }

// void init() {
//     memset(head, -1, sizeof(head));
//     memset(vis, 0, sizeof(vis));
//     memset(dfn, 0, sizeof(dfn));
//     memset(low, 0, sizeof(low));
//     memset(belong, 0, sizeof(belong));
//     while (!s.empty()) ins[s.top()] = 0, s.pop();
//     Amount = cnt = dfns = 0;
// }
// char s1[10], s2[10], s3[10];
// int main() {
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     init();
//     int n, k; scanf("%d%d", &k, &n);
//     // for (int i=1; i<=k; i++) add(i, i+k), add(i+k, i);
//     for (int i=0, a, b, c, _a, _b, _c; i<n; i++) {
//         scanf("%d%s%d%s%d%s", &a, s1, &b, s2, &c, s3);
//         if (s1[0]=='R') _a=a+k; else _a=a, a+=k;
//         if (s2[0]=='R') _b=b+k; else _b=b, b+=k;
//         if (s3[0]=='R') _c=c+k; else _c=c, c+=k;
//         add(_a, b); add(_a, c);
//         add(_b, a); add(_b, c);
//         add(_c, a); add(_c, b);
//     }
//     for (int i=1; i<=(k<<1); i++) {
//         if (!vis[i]) tarjan(i);
//     }
//     bool flag=false;
//     for (int i=1; i<=k; i++) {
//         if (belong[i]==belong[i+k]) {
//             flag=true; break;
//         }
//     }
//     if (flag) puts("-1");
//     else {
//         tp(k);
//         for (int i=1; i<=k*2; i++) {
//             if (color[belong[i]]=='R') {
//                 if (i<=k) ans[i]='R';
//                 else ans[i-k]='B';
//             } 
//             // printf("%c", color[belong[i]]);
//         }
//         for (int i=1; i<=k; i++) printf("%c", ans[i]);
//     }
//     return 0;
// }