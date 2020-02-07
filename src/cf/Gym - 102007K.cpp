#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+100;
int ind[maxn];
vector<int> v[maxn];
vector<int> leaf;
void dfs(int x, int fa) {
    for (int a:v[x]) {
        if (a==fa) continue;
        dfs(a, x);
    }
    if (ind[x]==1) {
        leaf.push_back(x);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, h; scanf("%d%d", &n, &h);
    for (int i=1, a, b; i<n; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b); ind[a]++;
        v[b].push_back(a); ind[b]++;
    }
    dfs(h, -1);
    printf("%d\n", int(leaf.size()+1)/2);
    int half=leaf.size()/2;
    for (int l=0; l<half; l++) {
        printf("%d %d\n", leaf[l+half], leaf[l]);
    }
    if (leaf.size()&1) {
        printf("%d %d\n", leaf[leaf.size()-1], leaf[0]);
    }
    return 0;
}