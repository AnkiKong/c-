#include <bits/stdc++.h>
#include <unistd.h>
#ifndef LOCAL
#pragma GCC optimize(3)
#endif
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
multiset<int> que;
queue<int> que2, que3;
pthread_mutex_t lck, lck2, lck3, lck4;
int ans;
void FCFS(int);
void SSTF(int);
void ele_SCAN(int);
void C_SCAN(int);
int da[500];
int main() {
// #ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif
    IOS;
    int cnt=400;
    for (int i=0; i<cnt; i+=2) {
        int type = rand()%4, rnd=rand()%500;
        if (type<2) {
            da[i]=rnd; da[i+1]=rnd+1;
        } else if (type == 2) {
            da[i]=rnd+500; da[i+1]=rnd+501;
        } else {
            da[i]=rnd+1000; da[i+1]=rnd+1001;
        }
    }
    
    pthread_mutex_init(&lck, NULL);
    pthread_mutex_init(&lck2, NULL);
    pthread_mutex_init(&lck3, NULL);
    pthread_mutex_init(&lck4, NULL);
    FCFS(cnt);
    thread th(SSTF, cnt);
    thread th2(ele_SCAN, cnt);
    thread th3(C_SCAN, cnt);
    for (int i=1; i<cnt; i++) {
        pthread_mutex_lock(&lck);
        que.insert(da[i]);
        pthread_mutex_unlock(&lck);

        pthread_mutex_lock(&lck2);
        que2.push(da[i]);
        pthread_mutex_unlock(&lck2);

        pthread_mutex_lock(&lck3);
        que3.push(da[i]);
        pthread_mutex_unlock(&lck3);

        if (i%10==0) sleep(1);
    }
    th.join();
    th2.join();
    th3.join();
    return 0;
}
void FCFS(int cnt) {
    int ans=0, now=da[0];
    for (int i=1; i<cnt; i++) {
        ans+=abs(now-da[i]);
        now=da[i];
    }
    pthread_mutex_lock(&lck4);
    cout << "FCFS: " << ans << endl;
    pthread_mutex_unlock(&lck4);
}
void SSTF(int cnt) {
    int now=da[0], near, dis; int ans=0;
    for (int i=1; i<cnt; i++) {
        pthread_mutex_lock(&lck);
        if (que.empty())  {
            pthread_mutex_unlock(&lck);
            sleep(2); i--;
            continue;
        }
        dis=inf;
        for (auto a:que) {
            if (abs(a-now)<dis) near=a, dis=abs(a-now);
        }
        que.erase(que.lower_bound(near));
        ans+=abs(now-near); now=near;
        pthread_mutex_unlock(&lck);
    }
    pthread_mutex_lock(&lck4);
    cout << "SSTF: " << ans << endl;
    pthread_mutex_unlock(&lck4);
    return ;
}
void ele_SCAN(int cnt) {
    int dir=1, now=da[0], ans=0;
    priority_queue<int> que0;
    priority_queue<int, vector<int>, less<int> > que1;
    for (int i=1; i<cnt; i++) {
        pthread_mutex_lock(&lck2);
        if (que0.empty() && que1.empty() && que2.empty()) {
            pthread_mutex_unlock(&lck2);
            sleep(2); i--; continue;
        }
        int tmp;
        while (!que2.empty()) {
            tmp=que2.front(); que2.pop();
            if (dir == 1) {
                if (now<=tmp) que1.push(tmp);
                else que0.push(tmp);
            } else {
                if (now>=tmp) que0.push(tmp);
                else que1.push(tmp);
            }
        }
        pthread_mutex_unlock(&lck2);
        if (dir==1) {
            while (!que1.empty()) {
                tmp=que1.top(); que1.pop(); i++;
                ans += abs(now-tmp); now=tmp;
            }
            if (!que0.empty()) dir=0;
            while (!que0.empty()) {
                tmp=que0.top(); que0.pop(); i++;
                ans += abs(now-tmp); now=tmp;
            }
        } else {
            while (!que0.empty()) {
                tmp=que0.top(); que0.pop(); i++;
                ans += abs(now-tmp); now=tmp;
            }
            if (!que1.empty()) dir=1;
            while (!que1.empty()) {
                tmp=que1.top(); que1.pop(); i++;
                ans += abs(now-tmp); now=tmp;
            }
        }
    }
    pthread_mutex_lock(&lck4);
    cout << "ele-SCAN: " << ans << endl;
    pthread_mutex_unlock(&lck4);
}
void C_SCAN(int cnt) {
    int now=da[0], ans=0, nowQue=0;
    priority_queue<int, vector<int>, less<int> > que[2];
    for (int i=1; i<cnt; i++) {
        pthread_mutex_lock(&lck3);
        if (que2.empty()) {
            pthread_mutex_unlock(&lck3);
            sleep(2); i--; continue;
        }
        int tmp;
        while (!que3.empty()) {
            tmp=que3.front(); que3.pop();
            if (now<=tmp) que[nowQue].push(tmp);
            else que[nowQue^1].push(tmp);
        }
        pthread_mutex_unlock(&lck3);
        while (!que[nowQue].empty()) {
            tmp=que[nowQue].top(); que[nowQue].pop(); i++;
            ans += abs(now-tmp); now=tmp;
        }
        if (!que[nowQue^1].empty()) nowQue^=1;
    }
    pthread_mutex_lock(&lck4);
    cout << "C-SCAN: " << ans << endl;
    pthread_mutex_unlock(&lck4);
}