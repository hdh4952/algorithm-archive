#include <bits/stdc++.h>

using namespace std;

int n, m, maxHeight, res;
int arr[302][302], arr2[302][302];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
bool vis[302][302];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (maxHeight < arr[i][j]) maxHeight = arr[i][j];
        }
    }

    while (maxHeight) {
        // 빙산 덩어리 수 세기
        int iceberg = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                if (arr[i][j] > maxHeight) maxHeight = arr[i][j];
                if (vis[i][j] == false && arr[i][j] > 0) {
                    iceberg++;
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    vis[i][j] = true;
                    while (!Q.empty()) {
                        int size = Q.size();
                        for (int u = 0; u < size; u++) {
                            int x = Q.front().first, y = Q.front().second;
                            Q.pop();
                            int cnt = 0;
                            if (arr[x + 1][y] == 0) cnt++;
                            if (arr[x - 1][y] == 0) cnt++;
                            if (arr[x][y + 1] == 0) cnt++;
                            if (arr[x][y - 1] == 0) cnt++;
                            if (vis[x + 1][y] == false && arr[x + 1][y]) {
                                Q.push({x + 1, y});
                                vis[x + 1][y] = true;
                            }
                            if (vis[x - 1][y] == false && arr[x - 1][y]) {
                                Q.push({x - 1, y});
                                vis[x - 1][y] = true;
                            }
                            if (vis[x][y + 1] == false && arr[x][y + 1]) {
                                Q.push({x, y + 1});
                                vis[x][y + 1] = true;
                            }
                            if (vis[x][y - 1] == false && arr[x][y - 1]) {
                                Q.push({x, y - 1});
                                vis[x][y - 1] = true;
                            }
                            if (cnt >= arr[x][y]) arr2[x][y] = 0;
                            else arr2[x][y] = arr[x][y] - cnt;
                        }
                    }
                }
            }
        }
        if (iceberg >= 2) {
            cout << res;
            return 0;
        } else if (iceberg == 0) break;
        // 빙산 녹는 과정
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                arr[i][j] = arr2[i][j];
            }
        }
        memset(vis, false, sizeof(vis));
        res++;
    }
    cout << "0";
}