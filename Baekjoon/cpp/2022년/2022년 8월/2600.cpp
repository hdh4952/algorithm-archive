#include <bits/stdc++.h>
using namespace std;

int b[3], k[2];
int memo[510][510];

int isWin(int x, int y) {
    if(x == 0 && (y == b[0] || y == b[1] || y == b[2])) return 1;
    if(y == 0 && (x == b[0] || x == b[1] || x == b[2])) return 1;
    if(memo[x][y] == 1 || memo[y][x] == 1) return 1;
    if(memo[x][y] == 2 || memo[y][x] == 2) return 2;

    for(int i=0 ; i<3 ; i++) {
        if(x >= b[i] && isWin(x - b[i], y) == 2) {
            return memo[x][y] = memo[y][x] = 1;
        }
    }

    for(int i=0 ; i<3 ; i++) {
        if(y >= b[i] && isWin(x, y - b[i]) == 2) {
            return memo[x][y] = memo[y][x] = 1;
        }
    }

    return memo[x][y] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0 ; i<3 ; i++) cin >> b[i];

    for(int i=0 ; i<5 ; i++) {
        cin >> k[0] >> k[1];
        if(isWin(k[0], k[1]) == 1) cout << "A\n";
        else cout << "B\n";
    }
}