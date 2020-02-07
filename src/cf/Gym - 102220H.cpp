#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
#define lowbit(x) (-x&x)
ll a[maxn], b[maxn];
ll s1[maxn], s2[maxn];
int n;
void add(int val, int pos, ll *arr) {
    for (; pos<=n; pos+=lowbit(pos)) {
        arr[pos]+=val;
    }
}
ll query(int pos, ll *arr) {
    ll ans=0;
    for (; pos; pos-=lowbit(pos)) {
        ans+=arr[pos];
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int t; cin >> t;
    for (int m; t--; ) {
        cin >> n >> m;
        for (int i=0; i<=n+10; i++) s1[i]=s2[i]=0;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            b[i]=a[i]-a[i-1];
            add(max(b[i], 0LL), i, s1);
            add(b[i], i, s2);
        }
        for (ll o, l, r, k; m--; ) {
            cin >> o >> l >> r;
            if (o==1) {
                cin >> k;
                add(k, l, s2);
                add(-k, r+1, s2);
                if (b[l]<0) {
                    if (b[l]+k>0) add(b[l]+k, l, s1);
                } else {
                    add(k, l, s1);
                }
                b[l]+=k;
                if (b[r+1]>0) add(-min(k, b[r+1]), r+1, s1);
                b[r+1]-=k;
            } else {
                cout << (query(l, s2)+query(r, s1)-query(l, s1)) << "\n";
            }
        }
    }
    return 0;
}