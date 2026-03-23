#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int len[] = {0, 0, 0, 0}; // 세로
int wid[] = {0, 0, 0}; // 가로
int arr[20][20];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void roll(int dir) {
    if(dir == 1) {  // 동
        int tmp = wid[0];
        wid[0] = wid[1];
        wid[1] = wid[2];
        wid[2] = len[3];
        len[3] = tmp;
        len[1] = wid[1];
    }
    if(dir == 2) {  // 서
        int tmp = wid[2];
        wid[2] = wid[1];
        wid[1] = wid[0];
        wid[0] = len[3];
        len[3] = tmp;
        len[1] = wid[1];
    }
    if(dir == 3) {  // 북
        int tmp = len[3];
        len[3] = len[2];
        len[2] = len[1];
        len[1] = len[0];
        len[0] = tmp;
        wid[1] = len[1];
    }
    if(dir == 4) {  // 남
        int tmp = len[0];
        len[0] = len[1];
        len[1] = len[2];
        len[2] = len[3];
        len[3] = tmp;
        wid[1] = len[1];
    }
}

bool isMove(int dir) {
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> x >> y >> k;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            cin >> arr[i][j];

    int dir;
    while(k--) {
        cin >> dir;
        if(!isMove(dir)) continue;
        roll(dir);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!arr[nx][ny]) arr[nx][ny] = wid[1];
        else {
            wid[1] = len[1] = arr[nx][ny];
            arr[nx][ny] = 0;
        }
        x = nx;
        y = ny;
        cout << len[3] << "\n";
    }
}