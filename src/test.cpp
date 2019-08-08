#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5+10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 78294349;
const double eps = 1e-8;
const int maxn=3e6;
const int maxm=1e7;
int deta[maxn];
int ans[20][20];
int vis[101];
int mn[20];
queue<int> q;
void bfs(int a, int b) {
    memset(vis, 0, sizeof(vis));
    q.push(0); vis[0]=1;
    while (!q.empty()) {
        int x=q.front(); q.pop();
        if (x+a<=100 && !vis[x+a]) vis[x+a]=vis[x]+1, q.push(x+a);
        if (x+b<=100 && !vis[x+b]) vis[x+b]=vis[x]+1, q.push(x+b);
    }
    for (int i=0; i<=100; i++) vis[i]--;
    for (int i=0; i<20; i++) mn[i]=1e9;
    if (a && b) vis[0]=-1;
    for (int i=0; i<=100; i++) 
        if (vis[i]!=-1) 
            mn[i%10]=min(mn[i%10], vis[i]);
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s; cin >> s;
    int sz=s.size();
    for (int i=0; i+1<sz; i++) {
        if (s[i+1]>=s[i]) deta[i]=s[i+1]-s[i];
        else deta[i]=s[i+1]-s[i]+10;
    }
    for (int i=0; i<10; i++) {
        for (int j=i; j<10; j++) {
            int aans=0; bfs(i, j);
            for (int k=0; k+1<sz; k++) {
                if (mn[deta[k]]==1e9) {
                    aans=-1; break;
                } else {
                    aans+=max(0, mn[deta[k]]-1);
                }
            }
            ans[i][j]=ans[j][i]=aans;
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}
