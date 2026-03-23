#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
bool vis[101][101];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
int t, cnt, res[10000];

void bfs(int i, int j) {
    t = 1;
    vis[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i,j});
    while(!q.empty()) {
        int size = q.size();
        for(int u=0 ; u<size ; u++) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int dir=0 ; dir<4 ; dir++) {
                int nx = x+px[dir], ny = y + py[dir];
                if(vis[nx][ny]) continue;
                vis[nx][ny] = true;
                if(arr[nx][ny]) {
                    q.push({nx, ny});
                    t++;
                }

            }
        }
    }
    res[cnt++] = t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, r, c;

    cin >> n >> m >> k;

    while(k--) {
        cin >> r >> c;
        arr[r][c] = 1;
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(arr[i][j] == 1 && !vis[i][j]) {
                bfs(i,j);
            }
        }
    }

    sort(res, res+cnt);
    cout << res[cnt-1];

}