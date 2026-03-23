#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d, res;
int dx[] = {-1, 0, 1, 0, -1, 0, 1, 0};   // 북동남서북동남서
int dy[] = {0, 1, 0, -1, 0, 1, 0, -1};
int arr[50][50]; // 0: 청소X, 1: 벽, 2: 청소O

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            cin >> arr[i][j];

    bool flag = false;
    while(!flag) {
        if(!arr[r][c]) {
            arr[r][c] = 2;   // 현재 위치를 청소한다
            res++;
        }
        for(int dir=d%4+3 ; dir>=d%4 ; dir--) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];
            if(!arr[nx][ny]) {  // 2-a
                r = nx;
                c = ny;
                d = dir;
                break;
            }else if(dir == d%4 && arr[r+dx[dir+2]][c+dy[dir+2]] == 1) {
                flag = true;
                break;
            }else if(dir == d%4 && arr[r+dx[dir+2]][c+dy[dir+2]] == 2) {
                r = r+dx[dir+2];
                c = c+dy[dir+2];
                d = dir;
                break;
            }
        }

    }

    cout << res;
}