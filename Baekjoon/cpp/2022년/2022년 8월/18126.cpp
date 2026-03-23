#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool vis[5010];
int n, a, b;
ll c, maxLength;
ll cost[5010][5010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0 ; i<n-1 ; i++) {
        cin >> a >> b >> c;
        cost[a][b] = cost[b][a] = c;
    }

    queue<pair<int, ll>> q;
    q.push({1, 0});
    vis[1] = true;

    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0 ; i<qsize ; i++) {
            int now = q.front().first;
            ll len = q.front().second;
            q.pop();
            if(len > maxLength) maxLength = len;
            for(int nxt=1 ; nxt<n+1 ; nxt++) {
                if(vis[nxt] || !cost[now][nxt]) continue;
                vis[nxt] = true;
                q.push({nxt, len + cost[now][nxt]});
            }
        }
    }

    cout << maxLength;
}