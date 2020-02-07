#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M=510;

bool isaMp[M][M], hasMp[M][M];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
#endif // LOCAL
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    unordered_map<string, short>s2i;
    cin >> n >> m;
    string s1, s2, s3;
    short a, b;
    short tot=1;
    for (int i=0; i<n; i++) {
        cin >> s1 >> s2 >> s3;
        if (s2i.count(s1)) a=s2i[s1];
        else s2i[s1]=a=tot++;
        if (s2i.count(s3)) b=s2i[s3];
        else s2i[s3]=b=tot++;
        if (s2[0]=='i') isaMp[a][b]=1;
        else hasMp[a][b]=1;
    }
    for (int i=1; i<tot; i++) {
        isaMp[i][i]=1;
    }
    for (int k=1; k<tot; k++) 
        for (int i=1; i<tot; i++) 
            for (int j=1; j<tot; j++) 
                if (isaMp[i][k] && isaMp[k][j]) 
                    isaMp[i][j]=1;

    for (int i=1; i<tot; i++) {
        for (int j=1; j<tot; j++) 
            if (isaMp[i][j]) 
                for (int m=1; m<tot; m++) 
                    hasMp[i][m]|=hasMp[j][m];
        for (int j=1; j<tot; j++) 
            if (hasMp[i][j]) 
                for (int m=1; m<tot; m++) 
                    hasMp[i][m]|=isaMp[j][m];  
    }
    for (int k=1; k<tot; k++) 
        for (int i=1; i<tot; i++) 
            for (int j=1; j<tot; j++) 
                if (hasMp[i][k] && hasMp[k][j]) 
                    hasMp[i][j]=1;

    for (int i=1; i<=m; i++) {
        cout << "Query " << i << ": ";
        cin >> s1 >> s2 >> s3;
        if (s2i.count(s1)) a=s2i[s1];
        else s2i[s1]=a=tot++;
        if (s2i.count(s3)) b=s2i[s3];
        else s2i[s3]=b=tot++;
        if (s2[0]=='i') {
            cout << ((isaMp[a][b] || a==b)?"true":"false") <<"\n";
        } else {
            cout << (hasMp[a][b]?"true":"false") <<"\n";
        }
    }
    return 0;
}