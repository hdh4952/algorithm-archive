#include <bits/stdc++.h>
using namespace std;

void makePaper(int N, int x, int y, vector<vector<int>> &v, vector<int> &res) {
  if(N == 1) {
    res[v[x][y] + 1]++;
    return;
  }
  int check = v[x][y];
  bool isDiff = false;
  for(int i=x ; i<x+N ; i++) {
    for(int j=y ; j<y+N ; j++) {
      if(v[i][j] != check) {
        isDiff = true;
        break;
      }
    }
    if(isDiff) break;
  }

  if(!isDiff) {
    res[check + 1]++;
    return;
  }
  int answer = 0;
  for(int i=x ; i<x+N ; i+=N/3) {
    for(int j=y ; j<y+N ; j+=N/3) {
      makePaper(N/3, i, j, v, res);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  vector<vector<int>> v(N, vector<int>(N));
  for(auto &i : v)
    for(auto &j : i)
      cin >> j;

  vector<int> res(3, 0);
  makePaper(N, 0, 0, v, res);
  for_each(res.begin(), res.end(), [](int ans) {
    cout << ans << "\n";
  });
}