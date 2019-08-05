#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
int month[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getWeek(int y, int m, int d) {
    if (m<3) m+=12, y--;
    int c=y/100; y%=100;
    return ((y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7+7)%7;
}
string date[maxn];
int toInt[10];
int cToInt(char c) {
    return toInt[c-'A'];
}
bool check(int i) {
    string& tp=date[i];
    int y=cToInt(tp[0])*1000+cToInt(tp[1])*100+cToInt(tp[2])*10+cToInt(tp[3]);
    int m=cToInt(tp[5])*10+cToInt(tp[6]);
    int d=cToInt(tp[8])*10+cToInt(tp[9]);
    if ((y%4==0 && y%100!=0) || y%400==0) month[2]=29;
    else month[2]=28;
    if (y<1600 || y>9999 || m<1 || m>12 || d<1 || d>month[m]) return false;
    // printf("%d-%d-%d\n", y, m, d);
    return getWeek(y, m, d)==5;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IOS;
    int T; cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        int n; cin >> n;
        for (int i=0; i<n; i++) cin >> date[i];
        for (int i=0; i<10; i++) toInt[i]=i;
        sort(date, date+n);
        n=unique(date, date+n)-date;
        bool flag;
        do {
            flag=true;
            for (int i=0; i<n; i++) {
                if (!check(i)) {
                    flag=false; break;
                }
            }
            if (flag) break;
        } while (next_permutation(toInt, toInt+10));
        printf("Case #%d: ", TT);
        if (flag) {
            for (int i=0; i<10; i++) printf("%d", toInt[i]);
            puts("");
        } else {
            puts("Impossible");
        }
    }
    return 0;
}