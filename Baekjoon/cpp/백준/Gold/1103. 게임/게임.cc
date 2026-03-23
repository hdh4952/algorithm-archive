#include <bits/stdc++.h>
using namespace std;

vector<int> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
bool Inf;
int N, M;

int moveCoin(vector<vector<char>> &v, vector<vector<bool>> &vis, vector<vector<int>> &cnt, int x, int y) {
  vis[x][y] = true;
  int answer = 1;

  for(int dir=0 ; dir<4 ; dir++) {
    int nx = x + dx[dir] * (v[x][y] - '0'), ny = y + dy[dir] * (v[x][y] - '0');
    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
    if(vis[nx][ny] || Inf) {
      Inf = true;
      return 0;
    }
    if(v[nx][ny] == 'H') continue;
    if(cnt[nx][ny]) answer = max(answer, cnt[nx][ny] + 1);
    else answer = max(answer, moveCoin(v, vis, cnt, nx, ny) + 1);
  }

  vis[x][y] = false;
  return cnt[x][y] = max(answer, cnt[x][y]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;

  vector<vector<int>> cnt(N, vector<int>(M, 0));
  vector<vector<char>> v(N, vector<char>(M));
  vector<vector<bool>> vis(N, vector<bool>(M, false));

  for(auto &i : v)
    for(auto &j: i)
      cin >> j;

  int answer = moveCoin(v, vis, cnt, 0, 0);
  if(Inf) cout << "-1";
  else cout << answer;
}