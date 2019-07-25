#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int M=1e5+100;
const int N=110;
int L[M], S[M], V[M];
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    for (int n; ~scanf("%d", &n); ) {
        double ans=0, sum=0;
        for (int i=0; i<=n; i++) scanf("%d", L+i);
        for (int i=0; i<=n; i++) scanf("%d", S+i);
        for (int i=0; i<=n; i++) scanf("%d", V+i);
        
        for (int i=0; i<=n; i++) {
            ans=max(ans, 1.0*(S[i]+sum)/V[i]);
            sum += L[i+1];
        }
        printf("%.10f\n", ans);
    }

    return 0;
}