#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+100;
int n;
int sum[maxn];
inline int lowbit(int x) {
    return -x&x;
}
inline void update(int x, int val) {
    for (; x<=n; x+=lowbit(x)) {
        sum[x]+=val;
    }
}
inline int query(int x) {
    int ans=0;
    for (; x; x-=lowbit(x)) {
        ans+=sum[x];
    }
    return ans;
}
#define pii pair<int,int>
int ans[maxn];
vector<int> pos[maxn];
struct node {
    int l, r, id;
    bool operator < (const node& tmp) const {
        if (l!=tmp.l) return l<tmp.l;
        else return r<tmp.r;
    }
}que[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int q; scanf("%d%d", &n, &q);
        memset(sum, 0, sizeof(sum));
        for (int i=0; i<=n; i++) pos[i].clear();
        for (int i=1, a, b; i<n; i++) {
            scanf("%d%d", &a, &b);
            if (a>b) swap(a, b);
            update(b, 1);
            pos[a].push_back(b);
        }
        for (int i=0, a, b; i<q; i++) {
            scanf("%d%d", &a, &b);
            que[i]=node{a, b, i};
        }
        sort(que, que+q);
        int l=1;
        for (int i=0; i<q; i++) {
            for (; l<que[i].l; l++) {
                for (auto a:pos[l]) update(a, -1);
            }
            ans[que[i].id]=que[i].r-que[i].l+1-query(que[i].r);
        }
        for (int i=0; i<q; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}