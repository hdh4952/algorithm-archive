#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int r, s, sX, sY, cmp = -1, ans;
char arr[60][60];
bool isChecked[60][60];

int handshake(int x, int y) {
    int answer = 0;

    for(int i=-1 ; i<=1 ; i++) {
        for(int j=-1 ; j<=1 ; j++) {
            int nx = x + i;
            int ny = y + j;
            if(nx < 0 || ny < 0 || nx >= r || ny >= s) continue;
            if(isChecked[nx][ny]) continue;
            if(arr[nx][ny] == '.') continue;
            answer++;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> s;
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<s ; j++)
            cin >> arr[i][j];

    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<s ; j++) {
            if(arr[i][j] == '.') {
                int temp = handshake(i, j);
                if(temp > cmp) {
                    cmp = temp;
                    sX = i;
                    sY = j;
                }
            }
        }
    }
    if(cmp != -1) arr[sX][sY] = 'o';

    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<s ; j++) {
            isChecked[i][j] = true;
            if(arr[i][j] == '.') continue;
            ans += handshake(i, j);
        }
    }

    cout << ans;
}