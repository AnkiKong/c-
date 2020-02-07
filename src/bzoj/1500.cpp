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
const int maxn=5e5+1000;
int fa[maxn], ch[maxn][2], w[maxn], sz[maxn], sum[maxn];
int lmx[maxn], rmx[maxn], ans[maxn];
bool rev[maxn], tag[maxn];
int a[maxn], st[maxn];
char s[40];
int n, m, T, tot, root, top;
#define ls ch[x][0]
#define rs ch[x][1]
int newNode() {
    int x;
    if (top) x=st[top--];
    else x=++tot;
    ls=rs=fa[x]=0;
    tag[x]=rev[x]=0;
    sz[x]=1;
    sum[x]=w[x]=rmx[x]=lmx[x]=-inf;
    return x;
}
void update(int x) {
    if (!x) return;
    sz[x]=sz[ls]+sz[rs]+1;
    sum[x]=sum[ls]+sum[rs]+w[x];
    lmx[x]=max(lmx[ls], sum[ls]+w[x]+max(0, lmx[rs]));
    rmx[x]=max(rmx[rs], sum[rs]+w[x]+max(0, rmx[ls]));
    ans[x]=max(max(ans[ls], ans[rs]), max(0, rmx[ls])+w[x]+max(0, lmx[rs]));
}
void reverse(int x) {
    if (!x) return;
    swap(lmx[x], rmx[x]);
    swap(ls, rs);
    rev[x]^=1;
}
void replace(int x, int d) {
    if (!x) return;
    w[x]=d; sum[x]=d*sz[x];
    lmx[x]=rmx[x]=ans[x]=max(d, d*sz[x]);
    tag[x]=1; rev[x]=0;
}
void pushDown(int x) {
    if (rev[x]) {
        if (ls) reverse(ls);
        if (rs) reverse(rs);
        rev[x]=0;
    }
    if (tag[x]) {
        if (ls) replace(ls, w[x]);
        if (rs) replace(rs, w[x]);
        tag[x]=0;
    }
}
int dir(int x) {
    return x==ch[fa[x]][1];
}
void rotate(int x) {
    int y, z, a, b, c;
    y=fa[x]; z=fa[y]; b=dir(x); a=ch[x][!b];
    if (z==0) root=x;
    else {
        c=dir(y); ch[z][c]=x;
    }
    fa[x]=z; fa[y]=x; ch[x][!b]=y; ch[y][b]=a;
    if (a) fa[a]=y;
    update(y); update(x);
}
void down(int x) {
    if (fa[x]) down(fa[x]);
    pushDown(x);
}
void splay(int x, int i) {
    down(x);
    int y, z, b, c;
    while (fa[x]!=i) {
        y=fa[x]; z=fa[y];
        if (z==i) rotate(x);
        else {
            b=dir(x); c=dir(y);
            if (b^c) {
                rotate(x); rotate(x);
            } else {
                rotate(y); rotate(x);
            }
        }
    }
}
int findK(int x, int k) {
    pushDown(x);
    if (sz[ls]==k-1) return x;
    if (sz[ls]>k-1) return findK(ls, k);
    else return findK(rs, k-sz[ls]-1);
}
void buildTree(int l, int r, int x) {
    int mid=(l+r)>>1;
    w[x]=a[mid];
    if (l==r) {
        sum[x]=lmx[x]=rmx[x]=ans[x]=w[x];
        sz[x]=1; return;
    }
    if (l<mid) {
        ls=newNode(); fa[ls]=x;
        buildTree(l, mid-1, ls);
    }
    if (mid<r) {
        rs=newNode(); fa[rs]=x;
        buildTree(mid+1, r, rs);
    }
    update(x);
}
int Query(int l, int num) {
    int x=findK(root, l); splay(x, 0);
    int y=findK(rs, num+1); splay(y, x);
    return sum[ch[y][0]];
}
void Insert(int l, int num) {
    for (int i=1; i<=num; i++) {
        scanf("%d", a+i);
    }
    int x=findK(root, l+1); splay(x, 0);
    int y=findK(rs, 1); splay(y, x);
    ch[y][0]=newNode(); fa[ch[y][0]]=y;
    buildTree(1, num, ch[y][0]);
    update(y); update(x);
}
void erase(int x) {
    if (!x) return;
    st[++top]=x;
    if (ls) erase(ls);
    if (rs) erase(rs);
}
void Delete(int l, int num) {
    int x=findK(root, l); splay(x, 0);
    int y=findK(rs, num+1); splay(y, x);
    erase(ch[y][0]);
    fa[ch[y][0]]=0; ch[y][0]=0;
    update(y); update(x);
}
void Reverse(int l, int num) {
    int x=findK(root, l); splay(x, 0);
    int y=findK(rs, num+1); splay(y, x);
    reverse(ch[y][0]);
    update(y); update(x);
}
void Replace(int l, int num, int d) {
    int x=findK(root, l); splay(x, 0);
    int y=findK(rs, num+1); splay(y, x);
    replace(ch[y][0], d);
    update(y); update(x);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    lmx[0]=rmx[0]=ans[0]=-inf;
    tot=2; root=1;
    fa[1]=0; sz[1]=2; ch[1][1]=2; w[1]=sum[1]=lmx[1]=rmx[1]=-inf;
    fa[2]=1; sz[2]=1; w[2]=sum[2]=lmx[2]=rmx[2]=-inf;
    scanf("%d%d", &n, &T);
    for (int i=1; i<=n; i++) scanf("%d", a+i);
    ch[2][0]=newNode(); fa[ch[2][0]]=2;
    buildTree(1, n, ch[2][0]);
    update(2); update(1);
    while (T--) {
        int x, y, z;
        scanf("%s", s);
        if (s[2]=='X') printf("%d\n", ans[root]);
        else if (s[0]=='G') {
            scanf("%d%d", &x, &y);
            printf("%d\n", Query(x, y));
        } else if (s[0]=='I') {
            scanf("%d%d", &x, &y);
            Insert(x, y);
        } else if (s[0]=='D') {
            scanf("%d%d", &x, &y);
            Delete(x, y);
        } else if (s[0]=='R') {
            scanf("%d%d", &x, &y);
            Reverse(x, y);
        } else if (s[4]=='-') {
            scanf("%d%d%d", &x, &y, &z);
            Replace(x, y, z);
        }
    }
    return 0;
}