#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e6+10;
int e[maxn];  //欧拉表
ll a[maxn];  //gcd(xi, x)累和
void getE() {
    e[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!e[i]) {
            for (int j = i; j < maxn; j += i) {
                if (!e[j]) e[j] = j;
                e[j] = e[j]/i*(i-1);
            }
        }
        for (int j = 1; j * i < maxn; j++) {
            a[j * i] += j * e[i];
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    getE();
    for (int i = 1; i < maxn; i++) a[i] += a[i-1];
    int n;
    while (scanf("%d", &n) && n) {
        printf("%lld\n", a[n]);
    }
    return 0;
}