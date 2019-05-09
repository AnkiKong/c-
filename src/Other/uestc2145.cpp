#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const int maxn=6e6;
int cnt[maxn], nxt[maxn][2], nw, root;
queue<int> del;
int newNode() {
    int t;
    if (!del.empty()) t=del.front(), del.pop();
    else t=nw++;
    cnt[t]=0, nxt[t][0]=nxt[t][1]=0;
    return t;
}
void init() {
    root=newNode();
    cnt[root]=1, nxt[root][0]=nxt[root][1]=0;
}
void ins(int* s, int num) {
    int now=root, k=0;
    while (s[k]!=-1) {
        cnt[now]+=num;
        if (!nxt[now][s[k]]) nxt[now][s[k]]=newNode();
        now=nxt[now][s[k]];
        k++;
    }
    cnt[now]+=num;
}
bool search(int* s, int num) {
    int now=root, k=0;
    while (s[k]!=-1) {
        int Nxt=nxt[now][s[k]];
        if (!Nxt || cnt[Nxt]<num) return 0;
        now=Nxt; k++;
    }
    int Cnt=cnt[now]-(nxt[now][0]?cnt[nxt[now][0]]:0)-(nxt[now][1]?cnt[nxt[now][1]]:0);
    return Cnt>=num;
}
void delet(int* s, int num) {
    int now=root, k=0, Nxt;
    cnt[now]-=num;
    while (s[k]!=-1) {
        Nxt=nxt[now][s[k]];
        cnt[Nxt]-=num;
        if (!cnt[Nxt]) {
            nxt[now][s[k]]=0; k++;
            break;
        }
        now=Nxt; k++;
    }
    while (s[k]!=-1) {
        del.push(Nxt);
        Nxt=nxt[Nxt][s[k]];
        k++;
    }
    del.push(Nxt);
}
int query(int* s, int flag) {
    int now=root, ans=0, k=0;
    while (s[k]!=-1) {
        if (flag) {
            if (nxt[now][s[k]^1]) ans|=1<<(30-k), now=nxt[now][s[k]^1];
            else now=nxt[now][s[k]];
        } else {
            if (nxt[now][s[k]]) now=nxt[now][s[k]];
            else ans|=1<<(30-k), now=nxt[now][s[k]^1];
        }
        k++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int n; cin >> n;
    int da[40];
    for (int i=0, a, b; i<n; i++) {
        cin >> a >> b;
        int cnt=0;
        for (int i=30; i>-1; i--) {
            da[cnt++]=(b>>i)&1;
        }
        da[cnt]=-1;
        if (a==1) {
            ins(da, 1);
        } else if (a==2) {
            if (search(da, 1)) 
                delet(da, 1);
        } else {
            cout << query(da, 0) << " " << query(da, 1) << endl;
        }
    }
    return 0;
}