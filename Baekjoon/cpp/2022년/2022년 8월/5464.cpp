#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
int weight[2010];
int place[2010];
int cost[110];
bool isExist[110];
bool isParked;
queue<int> ready;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) cin >> cost[i];
    for(int i=1 ; i<=m ; i++) cin >> weight[i];
    for(int i=0 ; i<2*m ; i++) {
        cin >> k;
        if(k > 0) {
            isParked = false;
            for(int j=1 ; j<=n ; j++) {
                if(!isExist[j]) {
                    isExist[j] = true;
                    place[k] = j;
                    ans += cost[j] * weight[k];
                    isParked = true;
                    break;
                }
            }
            if(!isParked) ready.push(k);
        } else {
            if(!ready.empty()) {
                int nxt = ready.front();
                ready.pop();
                place[nxt] = place[-k];
                ans += cost[place[nxt]] * weight[nxt];
            } else isExist[place[-k]] = false;
        }
    }
    cout << ans;
}