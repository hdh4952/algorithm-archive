#include <bits/stdc++.h>
using namespace std;

int r, c, answer;
bool isArrive;
vector<int> dx{-1, 0, 1}, dy{1, 1, 1};

void makeLine(vector<vector<char>> &v, int x, int y) {
  v[x][y] = 'x';
  if(y == c - 1) {
    isArrive = true;
    answer++;
    return;
  }

  for(int dir=0 ; dir<3 ; dir++) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
    if(v[nx][ny] == 'x') continue;
    makeLine(v, nx, ny);
    if(isArrive) return;
  }
  //if(!isArrive) v[x][y] = '.';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;
  vector<vector<char>> v(r, vector<char>(c, 0));
  for(auto &i : v)
    for(auto &j : i)
      cin >> j;

  for(int i=0 ; i<r ; i++) {
    makeLine(v, i, 0);
    isArrive = false;
  }


  cout << answer;
}