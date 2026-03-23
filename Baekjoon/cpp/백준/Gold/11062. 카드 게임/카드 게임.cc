#include <bits/stdc++.h>
using namespace std;

int getScore(vector<int> &v, vector<vector<int>> &memo, int a, int b, vector<int> &total) {
  if(a == b)
    return v[a];
  if(memo[a][b])
    return memo[a][b];
  return memo[a][b] = max(total[b] - total[a - 1] - getScore(v, memo, a+1, b, total), total[b] - total[a - 1] - getScore(v, memo, a, b-1, total));
}

void solve() {
  int N, x;
  cin >> N;
  vector<int> v(N + 1), total(N + 1, 0);
  vector<vector<int>> memo(N + 1, vector<int>(N + 1, 0));
  for(int i=1 ; i<=N ; i++) {
    cin >> x;
    v[i] = x;
    total[i] = total[i-1] + x;
  }

  cout << getScore(v, memo, 1, N, total) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--)
    solve();
}