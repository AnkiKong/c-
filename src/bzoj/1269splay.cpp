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
int fa[maxn], ch[maxn][2], sz[maxn];
char w[maxn];
bool rev[maxn];
int a[maxn], st[maxn];
char str1[maxn];
char s[40];
int n, m, T, tot, root, top;
#define ls ch[x][0]
#define rs ch[x][1]
int newNode() {
    int x;
    if (top) x=st[top--];
    else x=++tot;
    ls=rs=fa[x]=0;
    rev[x]=0;
    sz[x]=1;
    w[x]=0;
    return x;
}
void update(int x) {
    if (!x) return;
    sz[x]=sz[ls]+sz[rs]+1;
}
void reverse(int x) {
    if (!x) return;
    swap(ls, rs);
    rev[x]^=1;
}
void replace(int x, int d) {
    if (!x) return;
    w[x]=d;
    rev[x]=0;
}
void pushDown(int x) {
    if (rev[x]) {
        if (ls) reverse(ls);
        if (rs) reverse(rs);
        rev[x]=0;
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
    w[x]=str1[mid];
    if (l==r) {
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
void Insert(int l, int num) {
    int x=findK(root, l+1); 
    splay(x, 0);
    int y=findK(rs, 1); 
    splay(y, x);
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
    tot=2; root=1;
    fa[1]=0; sz[1]=2;
    fa[2]=1; sz[2]=1;
    ch[2][0]=newNode(); fa[ch[2][0]]=2;
    buildTree(1, 1, ch[2][0]);
    update(2); update(1);
    int now=1; int n, x;
    scanf("%d", &n);
    char opt[50];
    while (n--) {
        scanf("%s", opt);
        if (opt[0]=='I') {
            scanf("%d%*c", &x);
            for (int i=0; i<x; i++) {
                str1[i]=getchar();
            }
            Insert(now, x);
        } else if (opt[0]=='M') {
            scanf("%d", &x); now=x+1;
        } else if (opt[0]=='D') {
            scanf("%d", &x);
            Delete(now, x);
        } else if (opt[0]=='R') {
            scanf("%d", &x);
            Reverse(now, x);
        } else if (opt[0]=='G') {
            printf("%c\n", w[findK(root, now+2)]);
        } else if (opt[0]=='P') {
            now--;
        } else if (opt[0]=='N') {
            now++;
        }
    }
    return 0;
}