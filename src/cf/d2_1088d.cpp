// #include <bits/stdc++.h>
// #ifndef LOCAL
// #pragma GCC optimize(3)
// #endif
// using namespace std;
// typedef long long ll;
// // const int maxn=;
// int _2[40];

// int main() {
// #ifdef LOCAL
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
//     _2[0] = 1;
//     for (int i = 1; i < 40; i++) _2[i] = _2[i-1] * 2;
//     int a = 0, b = 0, c;
//     int big;
//     printf("? 0 0\n");
//     fflush(stdout);
//     scanf("%d", &c);
//     if (c == 0) big = 0;
//     else if (c == 1) big = 1;
//     else big = 2;
//     int nowa = 0, nowb = 0;
//     int ansa = 0, ansb = 0;
//     if (c == 0)
//     for (int i = 29; i >= 0; i--) {
//         printf("? %d %d\n", _2[i], 0);
//         fflush(stdout);
//         scanf("%d", &c);
//         if (c == -1) {
//             nowa += _2[i];
//         }
//     }
//     else if(c == 1)
//     for (int i = 29; i >= 0; i--) {
//         printf("? %d %d\n", nowa|_2[i], nowb|_2[i]);
//         fflush(stdout);
//         scanf("%d", &c);
//         if (c == -1) {
//             nowb += _2[i]; ansa += _2[i];continue;
//         } else if (c == 1) {
//             printf("? %d %d\n", nowa, nowb|_2[i]);
//             fflush(stdout);
//             scanf("%d", &c);
//             if (c == -1) 
//         }
//     }
//     return 0;
// }