#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
int head[maxn], to[maxn<<1], w[maxn<<1], nxt[maxn<<1], vcnt;
void add(int a, int b, int c) {
    to[++vcnt]=b; w[vcnt]=c; nxt[vcnt]=head[a]; head[a]=vcnt;
}

int b[maxn][2][3];
int id[maxn][2][3];
int ans[maxn], d[maxn];
int fa[maxn][2];
void dfs1(int a, int fa) {
    for (int i=head[a], t, ww; i; i=nxt[i]) {
        if ((t=to[i])==fa) continue; ww=w[i]; d[t]=ww;
        dfs1(t, a);
        if (b[t][0][0]+ww>b[a][0][0]) {
            b[a][0][2]=b[a][0][1];    id[a][0][2]=id[a][0][1];
            b[a][0][1]=b[a][0][0];    id[a][0][1]=id[a][0][0];
            b[a][0][0]=b[t][0][0]+ww; id[a][0][0]=t;
        } else if (b[t][0][0]+ww>b[a][0][1]) {
            b[a][0][2]=b[a][0][1];    id[a][0][2]=id[a][0][1];
            b[a][0][1]=b[t][0][0]+ww; id[a][0][1]=t;
        } else if (b[t][0][0]+ww>b[a][0][2]) {
            b[a][0][2]=b[t][0][0]+ww; id[a][0][2]=t;
        }
    }
    b[a][1][0]=min(b[id[a][0][0]][0][0], max(b[id[a][0][0]][1][0], b[id[a][0][0]][0][1])+d[id[a][0][0]]);
    b[a][1][1]=min(b[id[a][0][1]][0][0], max(b[id[a][0][1]][1][0], b[id[a][0][1]][0][1])+d[id[a][0][1]]);
}
void dfs2(int a, int faa) {
    ans[a]=min(max(b[a][0][0], fa[a][1]), max(max(b[a][1][0], b[a][0][1]), fa[a][0]));
    for (int i=head[a], t, ww; i; i=nxt[i]) {
        t=to[i]; ww=w[i];
        if (t==faa) continue;
        if (id[a][0][0]==t) {
            fa[t][0]=max(b[a][0][1], fa[a][0])+ww;
            fa[t][1]=min(fa[t][0]-ww, min(max(max(b[a][1][1], b[a][0][2]), fa[a][0]), max(b[a][0][1], fa[a][1]))+ww);
        } else {
            fa[t][0]=max(b[a][0][0], fa[a][0])+ww;
            if (id[a][0][1]==t) {
                fa[t][1]=min(fa[t][0]-ww, min(max(max(b[a][1][0], b[a][0][2]), fa[a][0]), max(b[a][0][0], fa[a][1]))+ww);
            } else {
                fa[t][1]=min(fa[t][0]-ww, min(max(max(b[a][1][0], b[a][0][1]), fa[a][0]), max(b[a][0][0], fa[a][1]))+ww);
            }
        }
        dfs2(t, a);
    }
}
void init(int n) {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<2; j++)
            for (int k=0; k<3; k++)
                b[i][j][k]=0, id[i][j][k]=0;
        ans[i]=0; fa[i][0]=fa[i][1]=0; d[i]=0; head[i]=0;
    }
    vcnt=0;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    for (int n; t--; ) {
        scanf("%d", &n);
        init(n);
        for (int i=1, a, b, c; i<n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c); add(b, a, c);
        }
        dfs1(1, 0); dfs2(1, 0);
        int ans1=inf, ans2;
        for (int i=1; i<=n; i++) {
            if (ans1>ans[i]) {
                ans1=ans[i]; ans2=i;
            }
        }
        printf("%d %d\n", ans2, ans1);
    }
    return 0;
}