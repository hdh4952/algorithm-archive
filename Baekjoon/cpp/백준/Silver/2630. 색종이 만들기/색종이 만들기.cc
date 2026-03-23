#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

pair<int, int> f(int N, vector<vector<int>> v) {
  pair<int, int> color = {0, 0};
  if(N == 2) {
    REP(i, 0, 1) {
      REP(j, 0, 1) {
        if(v[i][j] == 0) color.first++;
        else color.second++;
      }
    }
  } else {
    for(int i=0 ; i<N ; i += N/2) {
      for(int j=0 ; j<N ; j+= N/2) {
        vector<vector<int>> v2(N/2, vector<int>(N/2));
        REP(x, i, i+N/2-1) {
          REP(y, j, j+N/2-1) {
            v2[x - i][y - j] = v[x][y];
          }
        }
        pair<int, int> tmp = f(N/2, v2);
        color.first += tmp.first;
        color.second += tmp.second;
      }
    }
  }

  if(color.first == 4 && color.second == 0) color = {1, 0};
  if(color.first == 0 && color.second == 4) color = {0, 1};
  return color;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(N, 0));
  for(auto &i : v)
    for(auto &j : i)
      cin >> j;

  pair<int, int> ans = f(N, v);
  cout << ans.first << "\n" << ans.second;
}