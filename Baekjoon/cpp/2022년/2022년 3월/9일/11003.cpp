#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, l;
deque<pair<ll, int>> dq;
ll now, dqSize, mcnt = 1, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    for(int i=1 ; i<=n ; i++) {
        cin >> now;
        cnt = 1;
        if(!dq.empty() && dq.back().first > now) {
            while(!dq.empty() && dq.back().first > now) {
                cnt += dq.back().second;
                dqSize -= dq.back().second;
                dq.pop_back();
            }
        }
        dq.push_back({now, cnt});
        dqSize += cnt;
        if(dqSize > l) {
            if(dq.front().second == mcnt) {
                dq.pop_front();
                dqSize--;
                mcnt = 1;
            }else {
                mcnt++;
                dqSize--;
            }
        }
        cout << dq.front().first << " ";
    }
}
