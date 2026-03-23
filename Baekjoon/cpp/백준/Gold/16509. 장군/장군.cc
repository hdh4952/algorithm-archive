#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
#define N 10
#define M 9
using namespace std;

int R1, C1, R2, C2;
bool vis[N][M];
vector<vector<pair<int, int>>> moveCnt{{{-1, 0}, {-1, 1}, {-1, 1}},
                                    {{0, 1}, {-1, 1}, {-1, 1}},
                                    {{0, 1}, {1, 1}, {1, 1}},
                                    {{1, 0}, {1, 1}, {1, 1}},
                                    {{1, 0}, {1, -1}, {1, -1}},
                                    {{0, -1}, {1, -1}, {1, -1}},
                                    {{0, -1}, {-1, -1}, {-1, -1}},
                                    {{-1, 0}, {-1, -1}, {-1, -1}}};

bool isCanMove(int x, int y, int idx) {
  REP(i, 0, 2) {
    x += moveCnt[idx][i].first;
    y += moveCnt[idx][i].second;
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    if(i != 2 && x == R2 && y == C2) return false;
  }

  return true;
}

int bfs(int sx, int sy, int ex, int ey) {
  int answer = 0;
  queue<pair<int, int>> q;
  q.push({sx, sy});

  while (!q.empty()) {
    int qsize = q.size();
    while(qsize--) {
      auto [x, y] = q.front();
      q.pop();
      if (x == ex && y == ey) return answer;
      REP(i, 0, 7) {
        if(isCanMove(x, y, i)) {
          int nx = x, ny = y;
          for(auto [dx, dy] : moveCnt[i]) {
            nx += dx;
            ny += dy;
          }
          if(vis[nx][ny]) continue;
          vis[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    answer++;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R1 >> C1 >> R2 >> C2;

  cout << bfs(R1, C1, R2, C2);
}