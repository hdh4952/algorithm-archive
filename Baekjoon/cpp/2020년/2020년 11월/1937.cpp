#include <bits/stdc++.h>
using namespace std;

int arr[501][501], n, cmp, res;
int memo[501][501];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};

int dfs(int a, int b) {
    if(memo[a][b]) return memo[a][b];
    int k = 0;
    for(int dir = 0 ; dir<4 ; dir++) {
        int nx = a + px[dir], ny = b + py[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(arr[nx][ny] > arr[a][b]) {
            memo[nx][ny] = dfs(nx, ny);
            k = max(k, memo[nx][ny]);
        }
    }
    return memo[a][b] = k + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(memo[i][j] == 0) {
                memo[i][j] = dfs(i, j);
                res = max(res, memo[i][j]);
            }
        }
    }

    cout << res;
}