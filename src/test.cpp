#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int M=1e5+100;
const int N=5e4;
 
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    map<string, int> st;
    st[s1]++; st[s2]++; st[s3]++;
    char str[5]= "mps", str2[4];
    memset(str2, 0, sizeof(str2));
    int ans=3;
    for (int i=1; i<9; i++) {
        for (int j=0; j<3; j++) {
            int tmp=0;
            if (i+3>10) continue;
            for (int k=0; k+i<=9 && k<3; k++) {
                str2[0]=i+k+'0'; str2[1]=str[j];
                string tp = string(str2);
                if (st[tp]==0) tmp++;
            }
            ans=min(ans, tmp);
        }
    }
    for (int i=1; i<=9; i++) {
        for (int j=0; j<3; j++) {
            str2[0]=i+'0'; str2[1]=str[j];
            string tp = string(str2);
            ans=min(ans, 3-st[tp]);
        }
    }
    cout << ans << endl;
    return 0;
}