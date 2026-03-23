#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  int N, K;
  cin >> N >> K;
  vector<vector<int>> v(N, vector<int> (N));
  vector<int> dx{0, 1, 0, -1}, dy{-1, 0, 1, 0};
  int idx = N*N, x = 0, y = 0, dir = 0;

  while(idx) {
    v[x][y] = idx--;
    int nx = x + dx[dir], ny = y + dy[dir];
    if(nx < 0 || ny < 0 || nx >= N || ny >= N || v[nx][ny]) {
      dir = (dir + 1) % 4;
      x += dx[dir];
      y += dy[dir];
    } else {
      x = nx;
      y = ny;
    }
  }
  pair<int, int> ans;
  for(int i=0 ; i<N ; i++) {
    for(int j=0 ; j<N ; j++) {
      cout << v[i][j] << " ";
      if(v[i][j] == K) ans = {i+1, j+1};
    }
    cout << "\n";
  }
  cout << ans.first << " " << ans.second;
}