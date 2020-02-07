#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int n;
int len[maxn];
bool inq[maxn];
int spfa() {
    queue<int> q;
    memset(len, 0x3f3f, sizeof(len));
    memset(inq, 0, sizeof(inq));
    inq[1] = 1, len[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        inq[now] = 0;
        int new1 = (now+1) % n;
        if (len[new1] > len[now] + 1) {
            len[new1] = len[now] + 1;
            if (!inq[new1]) inq[new1] = 1, q.push(new1);
        }
        new1 = (now*10) % n;
        if (len[new1] > len[now]) {
            len[new1] = len[now];
            if (!inq[new1]) inq[new1] = 1, q.push(new1);
        }
    }
    return len[0];
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    printf("%d\n", spfa());
    return 0;
}