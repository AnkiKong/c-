#include <bits/stdc++.h>

#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
const int mod=1e9+7;

vector<int> mp[maxn];
int sz[maxn];
void getSz(int x, int fa) {
    sz[x]=1;
    for (int t:mp[x]) {
        if (t==fa) continue;
        getSz(t, x);
        sz[x]+=sz[t];
    }
}
int up[maxn], down[maxn];
int u[maxn], d[maxn];
int a[maxn], b[maxn];

bool dfs(int x, int fa) {
    int dn=0, Up=1;
    for (int t:mp[x]) {
        if (t==fa) continue;
        if (!dfs(t, x)) return 0;
        dn+=d[t]; Up+=u[t];
    }
    d[x]=max(dn, down[x]);
    u[x]=min(Up, up[x]);
    return d[x]<=u[x];
}
int n;
bool check(int x) {
    for (int i=1; i<=n; i++) {
        up[i]=min(sz[i], x-b[i]);
        if (up[i]<0) return 0;
    }
    return dfs(1, 0) && u[1]>=x && d[1]<=x;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (; t--; ) {
        cin >> n;
        for (int i=0; i<=n; i++) a[i]=b[i]=up[i]=down[i]=u[i]=d[i]=0, mp[i].clear();
        for (int i=1, a, b; i<n; i++) {
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        getSz(1, 0);
        int A, B;
        bool flag=0;
        cin >> A;
        for (int i=0, x, y; i<A; i++) {
            cin >> x >> y;
            down[x]=max(down[x], y);
            if (down[x]>sz[x]) flag=1;
        }
        cin >> B;
        for (int i=0, x, y; i<B; i++) {
            cin >> x >> y;
            b[x]=max(b[x], y);
            if (y>n-sz[x]) flag=1;
        }
        if (flag) {
            cout << -1 << "\n";
        } else {
            int l=0, r=n, mid;
            for (; l<r; ) {
                mid=(l+r)>>1;
                if (check(mid)) r=mid;
                else l=mid+1;
            }
            cout << r << "\n";
        }
    }
    return 0;
}
