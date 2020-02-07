#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1200;
struct Point {
    ll x, y;
    int xx;
    Point(int _x=0, int _y=0): x(_x), y(_y) {
        if (y==0) {
            if (x>=0) xx=1;
            else xx=2;
        } else {
            if (y>0) xx=1;
            else xx=2;
        }
    }
    Point operator - (const Point& a) const {
        return Point(x-a.x, y-a.y);
    }
    Point operator + (const Point& a) const {
        return Point(x+a.x, y+a.y);
    }
    ll operator * (const Point& a) const {
        return x*a.x + y*a.y;
    }
    ll operator ^ (const Point& a) const {
        return x*a.y-y*a.x;
    }
    void in() {
        cin >> x >> y;
    }
}P[maxn];

bool cmp1(const Point& a, const Point& b) {
    if (a.xx==b.xx) return (a^b)>0;
    return a.xx<b.xx;
}
ll C2(ll n) {
    return n*(n-1)/2;
}
ll C3(ll n) {
    return n*(n-1)/2*(n-2)/3;
}
ll ans;
Point nw[maxn];
int cnt[maxn], cnts[maxn];
bool vis[maxn];
ll solve(int n) {
    ll res=C3(n);
    sort(nw, nw+n, cmp1);
    int tot=0; cnt[0]=1;
    for (int i=1; i<n; i++) {
        if ((nw[i]^nw[tot])==0 && nw[i]*nw[tot]>0) cnt[tot]++;
        else nw[++tot]=nw[i], cnt[tot]=1;
    }
    cnts[0]=cnt[0]; vis[0]=0;
    for (int i=1; i<=tot; i++) {
        cnts[i]=cnts[i-1]+cnt[i];
        vis[i]=0;
    }
    for (int i=0; i<=tot; i++) res-=C3(cnt[i]);
    n=tot+1;
    int pos=1%n;
    for (int i=0; i<=tot; i++) {
        for (; i!=pos && (nw[i]^nw[pos])>=0; pos=(pos+1)%n);
        int last=(pos-1+n)%n;
        int half;
        if (last>=i) half=cnts[last]-cnts[i];
        else half=cnts[tot]-cnts[i]+(last!=tot? cnts[last] : 0);
        if ((nw[i]^nw[last])==0 && i!=last) {
            if (vis[last]) res+=C2(cnt[i])*cnt[last]+C2(cnt[last])*cnt[i];
            else vis[i]=1;
        }
        res-=C2(half)*cnt[i]+C2(cnt[i])*half;
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int n; cin >> n;
    for (int i=0, x, y; i<n; i++) {
        // P[i].in();
        cin >> x >> y;
        P[i]=Point(x, y);
    }
    for (int i=0; i<n; i++) {
        int tot=0;
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            nw[tot++]=P[j]-P[i];
        }
        ans+=solve(tot);
    }
    cout << ans;
    return 0;
}