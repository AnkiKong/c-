#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
// const int maxn=;
const int inf = 0x3f3f3f3f;
struct node {
    int x, y;
    bool operator < (const node &a) const {
        return x < a.x;
        // return y < a.y;
    }
    void in() {
        scanf("%d%d", &x, &y);
    }
};
node da[10];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 0; i < 3; i++) {
        // scanf("%d%d", x+i, y+i);
        da[i].in();
    }
    sort(da, da+3);
    int sx = da[0].x, sy = da[0].y;
    int ex = da[1].x, ey = da[1].y;
    set< pair<int, int> > ans;
    
    while (sx < ex) ans.insert(make_pair(sx++, sy));
    while (sx > ex) ans.insert(make_pair(sx--, sy));
    while (sy < ey) ans.insert(make_pair(sx, sy++));
    while (sy > ey) ans.insert(make_pair(sx, sy--));
    sx = da[2].x, sy = da[2].y;
    ans.insert(make_pair(da[1].x, da[1].y));
    while (sx < ex) ans.insert(make_pair(sx++, sy));
    while (sx > ex) ans.insert(make_pair(sx--, sy));
    if (abs(da[0].y - sy) > abs(da[1].y - sy)) ey = da[1].y;
    else ey = da[0].y;
    while (sy < ey) ans.insert(make_pair(sx, sy++));
    while (sy > ey) ans.insert(make_pair(sx, sy--));
    printf("%d\n", ans.size());
    for (auto aa : ans) {
        printf("%d %d\n", aa.first, aa.second);
        // ans.pop();
    }
    return 0;
}