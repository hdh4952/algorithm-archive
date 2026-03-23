#include <bits/stdc++.h>

using namespace std;

int n, m, cheese, res;
int arr[100][100];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
void dfs(int i, int j) {
    arr[i][j] = -1;

    for(int dir=0 ; dir<4 ; dir++) {
        int nx = i + px[dir], ny = j+py[dir];
        if(nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
        if(arr[nx][ny] >= 1) arr[nx][ny]++;
        else if(arr[nx][ny] == 0) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    do {
        cheese = 0;
        dfs(0, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j] == 1 || arr[i][j] == 2) {
                    arr[i][j] = 1;
                    cheese++;
                }
                else arr[i][j] = 0;
            }
        }
        res++;
    } while (cheese != 0);

    cout << res;
}