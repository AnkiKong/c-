#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
struct node {
    int x, y, z, id;
    node(){}
    node(int iid) {
        scanf("%d%d%d", &x, &y, &z);
        id=iid;
    }
};
struct edge{
    int x, y;
    void in() {
        scanf("%d%d", &x, &y);
    }
}v[maxn];
int ans[maxn];
int fa[maxn], sz[maxn];
int op[maxn][2], opt;
int fin(int a) {
    while (a!=fa[a]) 
        a=fa[a];
    return a;
}
void com(int x, int y) {
    x=fin(x); y=fin(y);
    if (x==y) return;
    if (sz[x]<sz[y]) swap(x, y);
    fa[y]=x;
    sz[x]+=sz[y];
    op[++opt][0]=x; op[opt][1]=y;
}
void revCom() {
    while (opt) {
        sz[op[opt][0]] -= sz[op[opt][1]];
        fa[op[opt][1]] = op[opt][1];
        opt--;
    }
}
void solve(int l, int r, vector<node>& wait) {
    if (!wait.size()) {
        for (int i=l; i<=r; i++) {
            com(v[i].x, v[i].y);
        }
        return;
    }
    if (l==r) {
        for (node a:wait) {
            ans[a.id]=l;
        }
        com(v[l].x, v[l].y);
        return;
    }
    opt=0;
    int mid=(l+r)>>1;
    for (int i=l; i<=mid; i++) {
        com(v[i].x, v[i].y);
    }
    vector<node>ll, rr;
    for (node a:wait) {
        int lx=fin(a.x), ly=fin(a.y);
        if (lx!=ly && sz[lx]+sz[ly]>=a.z) ll.push_back(a);
        else if (lx==ly && sz[lx]>=a.z) ll.push_back(a);
        else rr.push_back(a);
    }
    revCom();
    solve(l, mid, ll);
    solve(mid+1, r, rr);
}
// bool mk[maxn];
// int id[maxn], idTmp[maxn];
// void solve(int l, int r, int sr, int st) {
//     if (sr>st) {
//         for (int i=l; i<=r; i++) {
//             com(v[i].x, v[i].y);
//         }
//         return;
//     }
//     if (l==r) {
//         for (int i=sr; i<=st; i++) {
//             ans[id[i]]=l;
//         }
//         com(v[l].x, v[l].y);
//         return;
//     }
//     opt=0;
//     int mid=(l+r)>>1;
//     for (int i=l; i<=mid; i++) {
//         com(v[i].x, v[i].y);
//     }
//     for (int i=sr; i<=st; i++) {
//         int fx=fin(query[id[i]].x), fy=fin(query[id[i]].y);
//         if (fx==fy && sz[fx]>=query[id[i]].z) mk[i]=1;
//         if (fx!=fy && sz[fx]+sz[fy]>=query[id[i]].z) mk[i]=1;
//     }
//     int tl=l-1, mid2;
//     for (int i=sr; i<=st; i++) {
//         if (mk[i]) idTmp[++tl]=id[i];
//     }
//     mid2=tl;
//     for (int i=sr; i<=st; i++) {
//         if (!mk[i]) idTmp[++tl]=id[i];
//     }
//     for (int i=sr; i<=st; i++) {
//         mk[i]=0; id[i]=idTmp[i];
//     }
//     revCom();
//     solve(l, mid, sr, mid2);
//     solve(mid+1, r, mid2+1, st);
// }
void init() {
    for (int i=0; i<maxn; i++) fa[i]=i, sz[i]=1;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++) {
        v[i].in();
    }
    int q; scanf("%d", &q);
    vector<node> all;
    for (int i=1; i<=q; i++) {
        all.push_back(node(i));
    }
    solve(1, m, all);
    for (int i=1; i<=q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}