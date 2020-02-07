#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5;
int a[maxn];
int LOG[maxn];
int mx[20][maxn];
int n, m;
int mxx(int l, int r) {
    return a[l]>=a[r] ? l : r;
}
void init() {
    LOG[0]=-1;
    for (int i=1; i<maxn; i++) LOG[i]=LOG[i>>1]+1;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mx[0][i]=i;
    }
    for (int i=1; (1<<i)<=n; i++) {
        for (int j=1; j+(1<<i)-1<=n; j++) {
            mx[i][j]=mxx(mx[i-1][j], mx[i-1][j+(1<<(i-1))]);
        }
    }
}
int query(int l, int r) {
    int tmp=LOG[r-l+1];
    return mxx(mx[tmp][l], mx[tmp][r-(1<<tmp)+1]);
}
int deps[maxn], ans[maxn];
int solve(int l, int r, int dep) {
    if (l>r) return -1;
    int p=query(l, r);
    deps[p]=dep;
    ans[p]=solve(l, p-1, dep+1)+1;
    int res=ans[p];
    while (p<r) {
        int q=query(p+1, r);
        if (a[q]!=a[p]) break;
        deps[q]=dep;
        int t=solve(p+1, q-1, dep+1)+1;
        res=max(res, t);
        ans[p]=max(ans[p], t);
        ans[q]=t;
        p=q;
    }
    ans[p]=max(ans[p], solve(p+1, r, dep+1)+1);
    res=max(res, ans[p]);
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    solve(1, n, 0);
    int l, r;
    for (int i=0; i<m; i++) {
        cin >> l >> r;
        if (!r) {
            cout << ans[l] << endl;
        } else {
            if (a[l]<a[r]) swap(l, r);
            if (l==r) cout << 0 << endl;
            else {
                int p;
                if (l>r) p=query(r, l-1);
                else     p=query(l+1, r);
                if (a[p]>=a[l]) {
                    cout << 0 << endl;
                } else {
                    cout << deps[r]-deps[l] << endl;
                }
            }
        }

    }
    return 0;
}