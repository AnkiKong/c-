#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
const double eps = 1e-6;
struct node {
    double a, b;
    int id;
    bool operator < (const node & tmp) const {
        if (fabs(a - tmp.a) < eps) return b < tmp.b;
        return a < tmp.a;
    }
};
double cal(node a, node b) {
    return (b.b - a.b) / (a.a - b.a);
}
node stk[maxn];
bool vis[maxn];
int top;
void inst(node a) {
    while(top){
        if (fabs(stk[top].a - a.a) < eps) top--;
        else if (top > 1 && cal(a, stk[top-1]) <= cal(stk[top], stk[top-1])) top--;
        else break;
    }
    stk[++top] = a;
}
node line[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &line[i].a, &line[i].b);
        line[i].id = i;
    }
    sort(line + 1, line + 1 + n);
    for (int i = 1; i <= n; i++) inst(line[i]);
    for (int i = 1; i <= top; i++) vis[stk[i].id] = 1;
    for (int i = 1; i <= n; i++) if (vis[i]) printf("%d ", i);
    return 0;
}