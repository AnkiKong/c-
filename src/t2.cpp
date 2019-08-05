#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#else
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long ll;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
struct Line{
    int k, b;
    Line(int _k=1, int _b=0) {
        k=_k, b=_b;
    }
    bool operator < (const Line& a) const {
        return 1LL*b*a.k > 1LL*a.b*k;
    }
};
Line le[maxn];
#define pii pair<int,int>
bool cmp(pii a, pii b) {
    return 1LL*a.first*b.second > 1LL*a.second*b.first;
}
vector<pii> aans;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    int t; scanf("%d", &t);
    for (int n, c; t--;) {
        scanf("%d%d", &n, &c);
        int sumk=0, sumb=0;
        for (int i=1, k, b; i<=n; i++) {
            scanf("%d%d", &k, &b);
            le[i]=Line(k, b);
            sumk+=k; sumb+=b;
        }
        sort(le+1, le+n+1);
        bool many=0;
        aans.clear();
        if (sumk==0 && sumb==c) many=1;
        else if (sumk!=0) {
            if (1LL*(c-sumb)*le[n].k>=-1LL*le[n].b*sumk) {
                int tp=__gcd(abs(sumk), abs(c-sumb));
                aans.push_back(pii(sumk/tp, (c-sumb)/tp));
            }
        }
        for (int i=n; i>1; i--) {
            sumb-=2*le[i].b; sumk-=2*le[i].k;
            if (sumk==0 && sumb==c) many=1;
            else if (sumk>0) {
                if (1LL*(c-sumb)*le[i-1].k>=-1LL*le[i-1].b*sumk && 1LL*(c-sumb)*le[i].k<=-1LL*le[i].b*sumk) {
                    int tp=__gcd(abs(sumk), abs(c-sumb));
                    aans.push_back(pii(sumk/tp, (c-sumb)/tp));
                }
            } else if (sumk<0) {
                if (1LL*(c-sumb)*le[i-1].k<=-1LL*le[i-1].b*sumk && 1LL*(c-sumb)*le[i].k>=-1LL*le[i].b*sumk) {
                    int tp=__gcd(abs(sumk), abs(c-sumb));
                    aans.push_back(pii(sumk/tp, (c-sumb)/tp));
                }
            }
        }
        sumb-=2*le[1].b; sumk-=2*le[1].k;
        if (sumk==0 && sumb==c) many=1;
        else if (sumk!=0) {
            if (1LL*(c-sumb)*le[1].k>=-1LL*le[1].b*sumk) {
                int tp=__gcd(abs(sumk), abs(c-sumb));
                aans.push_back(pii(sumk/tp, (c-sumb)/tp));
            }
        }
        if (many) {
            printf("-1\n");
        } else {
            for (int i=0; i<(int)aans.size(); i++) {
                pii& a=aans[i];
                if (a.first<0) a.first=-a.first, a.second=-a.second;
                if (a.second==0) a.first=1, a.second=0;
            }
            sort(aans.begin(), aans.end(), cmp);
            int ans=unique(aans.begin(), aans.end())-aans.begin();
            printf("%d", ans);
            for (int i=0; i<ans; i++) {
                pii& tp=aans[i];
                printf(" %d/%d", tp.second, tp.first==0?1:tp.first);
            }
            puts("");
        }
    }
    return 0;
}