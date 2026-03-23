#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[101];
int n, a, b, m, x, y, res;
bool vis[101], flag = false;

void bfs(int start) {
    vis[start] = true;
    queue<pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty()) {
        int next = q.front().first, value = q.front().second;
        q.pop();
        if(next == b) {
            flag = true;
            res = abs(value);
            return;
        }
        for(int i=0 ; i<v[next].size() ; i++) {
            if(vis[v[next][i].first]) continue;
            vis[v[next][i].first] = true;
            q.push({v[next][i].first, value + v[next][i].second});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> m;

    for(int i=0 ; i<m ; i++) {
        cin >> x >> y;
        v[x].push_back({y, 1});
        v[y].push_back({x, 1});
    }

    bfs(a);
    if(flag) cout << res;
    else cout << "-1";
}