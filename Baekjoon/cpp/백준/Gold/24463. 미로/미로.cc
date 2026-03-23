#include <bits/stdc++.h>
using namespace std;

vector<int> dx={-1, 1, 0, 0}, dy{0, 0, -1, 1};
vector<vector<char>> ans;
int cmp = 2000 * 2000;

void dfs(vector<vector<char>> &maze, vector<vector<bool>> &vis, int x, int y, int N, int M) {
  vis[x][y] = true;

  for(int dir=0 ; dir<4 ; dir++) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
    if(vis[nx][ny] || maze[nx][ny] != '.') continue;
    maze[nx][ny] = '#';
    if((nx == 0 || ny == 0 || nx == N-1 || ny == M-1)) {
      int cnt = 0;
      for(auto &i : maze)
        for(auto &j : i)
          if(j == '#') cnt++;

      if(cmp > cnt)
        ans = maze;
    }
    dfs(maze, vis, nx, ny, N, M);
    maze[nx][ny] = '.';
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<vector<char>> maze(N, vector<char>(M, 0));
  vector<vector<bool>> vis(N, vector<bool>(M, false));

  for(auto &i : maze)
    for(auto &j: i)
      cin >> j;

  pair<int, int> start;
  for(int i=0 ; i<N ; i++)
    for(int j=0 ; j<M ; j++)
      if((i == 0 || j == 0 || i == N-1 || j == M-1 )&& maze[i][j] == '.')
        start = {i, j};

  maze[start.first][start.second] = '#';
  dfs(maze, vis, start.first, start.second, N, M);
  for(auto &i : ans) {
    for(auto &j : i) {
      if(j == '.') cout << "@";
      else if(j == '#') cout << ".";
      else cout << j;
    }
    cout << "\n";
  }
}