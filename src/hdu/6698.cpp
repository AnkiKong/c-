#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
char buf[100000],*p1=buf,*p2=buf;
inline char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool read(auto &x){
    char c=nc();x=0;
    if(c==EOF) return false;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    return true;
}
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
struct node {
    int a, b, sum, id;
    node(int _a=0, int _b=0, int _c=0) : a(_a), b(_b), id(_c) {
        sum=a+b;
    }
};
node da[maxn];
struct node2 {
    int val, id, ty;
    node2(int _a=0, int _b=0, int _c=-1) : val(_a), id(_b), ty(_c) {} 
    bool operator < (const node2 & aa) const {
        if (val!=aa.val) return val>aa.val;
        return id < aa.id;
    }
    bool operator > (const node2 & aa) const {
        if (val!=aa.val) return val<aa.val;
        return id > aa.id;
    }
};
void print(int a) {
    if (a>=10) print(a/10);
    putchar('0'+a%10);
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int T; read(T);
    multiset<node2> q1, q2;
    multiset<node2, greater<node2> > qa1, qa2;
    for (int n; T--; ) {
        // cin >> n; 
        read(n);
        q1.clear(), q2.clear(), qa1.clear(), qa2.clear();
        for (int i=0, a, b; i<n; i++) {
            // cin >> a >> b;
            read(a); read(b);
            da[i]=node(a, b, i);
            q1.insert(node2(a, i, 0));
            q2.insert(node2(a+b, i));
        }
        int ans=0;
        for (int i=0; i<n*2; i++) {
            int tp1=0, tp2=0;
            if (qa1.size() && q2.size()) {
                tp1=q2.begin()->val - qa1.begin()->val;
            }
            if (q1.size()) {
                tp2=q1.begin()->val;
            }
            if (tp1>tp2) {
                node2 a=*qa1.begin(), b=*q2.begin();
                qa1.erase(a);
                q1.insert(a);
                if (a.ty==0) {
                    q1.erase(node2(da[a.id].b, a.id, 1));
                    q2.insert(node2(da[a.id].sum, a.id));
                }
                q2.erase(b);
                ans+=tp1;
            } else {
                node2 a = *q1.begin();
                q1.erase(q1.begin());
                qa1.insert(a);
                if (a.ty==0) {
                    q1.insert(node2(da[a.id].b, a.id, 1));
                    q2.erase(node2(da[a.id].sum, a.id));
                } else {
                    qa1.erase(node2(da[a.id].a, a.id, 0));
                }
                ans+=tp2;
            }
            print(ans);
            putchar(' ');
            // cout << ans << " ";
        }
        puts("");
    }
    return 0;
}