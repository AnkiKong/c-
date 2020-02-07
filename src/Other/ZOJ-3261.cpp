#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn=1e4 + 100;
int size[maxn];
int tr[maxn];

int fin(int a) {
    if (tr[a] != a) return tr[a] = fin(tr[a]);
    return a;
}
void com(int a, int b) {
    a = fin(a), b= fin(b);
    if (size[a] > size[b]) {
        tr[b] = tr[a];
    } else if (size[a] < size[b]) {
        tr[a] = tr[b];
    } else if (a < b) {
        tr[b] = tr[a];
    } else {
        tr[a] = tr[b];
    }
}
set<int> des;
struct node {
    int op, a, b;
    node(int aa, int bb, int cc=0) : op(aa), a(bb), b(cc){} 
};
void init(int n) {
    for (int i = 0; i <= n; i++) tr[i] = i;
    des.clear();
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    bool flag = 0;
    while (~scanf("%d", &n)) {
        init(n);
        for (int i = 0; i < n; i++) scanf("%d", size + i);
        vector<pii > line;
        int m, a, b; scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            if (a < b) swap(a, b);
            line.push_back(make_pair(a, b));
        }
        int q;
        char str[10];
        scanf("%d", &q);
        stack<node> query;
        for (int i = 0; i < q; i++) {
            scanf("%s", str);
            if (str[0] == 'd') {
                scanf("%d%d", &a, &b);
                if (a < b) swap(a, b);
                query.push(node(1, a, b));
                des.insert(a * 10000 + b);
            } else {
                scanf("%d", &a);
                query.push(node(0, a));
            }
        }
        for (auto aa : line) {
            if (des.count(aa.first * 10000 + aa.second)) continue;
            com(aa.first, aa.second);
        }
        stack<int> ans;
        while (!query.empty()) {
            node aa = query.top(); query.pop();
            if (aa.op == 1) com(aa.a, aa.b);
            else {
                if (size[fin(aa.a)] > size[aa.a]) ans.push(fin(aa.a));
                else ans.push(-1);
            }
        }
        if (flag)
            printf("\n");
        else
            flag = 1;
        while(!ans.empty()) {
            a = ans.top(); ans.pop();
            printf("%d\n", a);
        }
    }
    return 0;
}