#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int M=1e5+100;
const int N=110;
int k;
int sg[110];
int getSg(int n) {
    if (n == 0) return 0;
    if (sg[n] != -1) return sg[n];
    set<int> vis;
    if (n>=1)
        vis.insert(getSg(n-1));
    if (n>=2)
        vis.insert(getSg(n-2));
    if (n>=k)
        vis.insert(getSg(n-k));
    for (int i = 0; ; i++) if (!vis.count(i)) return sg[n] = i;
}
int cal(int n, int k) {
    if (k==3) return n%4!=0;
    if (k%3!=0) {
        return n%3!=0;
    } else {
        if (n%(k+1)==0) return 0;
        else if (n%(k+1)==k) return 1;
        return n%(k+1)%3!=0;
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    // for (k=3; k<100; k++) {
    //     memset(sg, -1, sizeof(sg));
    //     for (int i=0; i<100; i++) {
    //         cout << k << " " << i << " " <<  (getSg(i)!=0) << " " << cal(i, k) << endl;
            // if (!getSg(i)) {
            //     cout << k << " " << i << " " << cal(i, k) << endl;;
            // }
    //     }
    //     cout << endl;
    // }
    // int n, k; cin >> n >> k;
    int T; scanf("%d", &T);
    for (int TT = 1, n, k; TT <= T; TT++) {
        scanf("%d%d", &n, &k);
        printf("%s\n", cal(n, k)?"Alice":"Bob");
    }

    return 0;
}