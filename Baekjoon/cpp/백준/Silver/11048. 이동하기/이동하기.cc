#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, x;
  cin >> N >> M;
  vector<vector<int>> maze(N+1, vector<int>(M+1, 0));

  REP(r, 1, N)
    REP(c, 1, M)
      cin >> maze[r][c];

  REP(r, 1, N)
    REP(c, 1, M)
      maze[r][c] += max(maze[r-1][c], maze[r][c-1]);

  cout << maze[N][M];
}