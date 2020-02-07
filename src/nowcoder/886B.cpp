#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1)|1
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
const int mod=1000000007;
int ip[10];
string get(int l, int r) {
    string ans;
    char s[10];
    for (int i=0; i<8; i++) {
        if (l==i) {
            i=r;
            if (l==0) ans+=string("::");
            else ans += string(":");
            continue;
        }
        sprintf(s, "%x", ip[i]);
        ans+=string(s) + string(":");
    }
    if (ans.size()==2) return ans;
    if (r!=7) return ans.substr(0, ans.size()-1);
    return ans;
}
bool cmp(string a, string b) {
    if (a.size()==b.size()) return a<b;
    return a.size() < b.size();
}
char s[1000];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int t; cin >> t;
    vector<string> ans;
    for (int TT=1; t--; TT++) {
        cin >> s;
        for (int i=0, l=0; l<8; l++) {
            ip[l]=0;
            for (int j=0; j<16; j++, i++) {
                ip[l]=(ip[l]<<1)+s[i]-'0';
            }
        }
        ans.clear();
        for (int i=0, ii; i<8; i++) {
            if (ip[i]!=0) continue;
            int j=i+1;
            ii=i;
            for (; j<8; j++) {
                if (ip[j]!=0) {
                    break;
                }
            }
            i=j-1;
            if (j-ii>1)
                ans.push_back(get(ii, j-1));
        }
        // ans.push_back(string("1"));
        // ans.push_back(string("2"));
        ans.push_back(get(100, 100));
        sort(ans.begin(), ans.end(), cmp);
        cout << "Case #" << TT << ": ";
        cout << ans[0] << endl;
    }
     
    return 0;
}