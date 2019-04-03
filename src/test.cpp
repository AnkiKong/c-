#include <stdio.h>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=3e5+100;
const int mod=1e9+7;
int mn[10], mx[10], sm[10];
char str[100];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(0);
    int n;
    int t;
    cin>>t;
    int a;
    while (t--) {
        cin >>n;
        memset(mn, 0x3f, sizeof(mn));
        memset(sm, 0, sizeof(sm));
        memset(mx, 0, sizeof(mx));
        for (int i=0; i<n; i++) {
            for (int j=1; j<=6; j++) {
                cin>>a;
                mn[j]=min(mn[j], a);
                mx[j]=max(mx[j], a);
                sm[j]+=a;
            }
        }
        int q, m; cin>>q;
        double ans;
        string s;
        while (q--) {
            cin>>s>>m;
            if (s[1]=='u') ans=sm[m];
            else if (s[1]=='v') ans=1.0*sm[m]/n;
            else if (s[1]=='a') ans=mx[m];
            else if (s[1]=='i') ans=mn[m];
            cout << int(ans+0.5) << endl;
        }
    }
    
    return 0;
}