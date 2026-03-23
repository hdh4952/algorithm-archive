#include <bits/stdc++.h>
#define MAX 1000
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int H, W, answer;
vector<vector<char>> arr(MAX, vector<char>(MAX));
vector<int> dx{-1, -1, -1, 0, 0, 1, 1, 1},
    dy{-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  queue<pair<int, int>> q;
  cin >> H >> W;
  REP(i, 0, H - 1) {
    REP(j, 0, W - 1) {
      cin >> arr[i][j];
      if (arr[i][j] == '.') q.emplace(i, j);
    }
  }

  while (!q.empty()) {
    size_t qsize = q.size();
    REP(i, 1, qsize) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      REP(dir, 0, 7) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
        if (arr[nx][ny] == '.') continue;
        arr[nx][ny] -= 1;
        if (arr[nx][ny] == '0') {
          arr[nx][ny] = '.';
          q.emplace(nx, ny);
        }
      }
    }
    answer++;
  }

  cout << answer - 1;
}