#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<int> game(vector<int> v) {
  if(v.size() == 2) return v;
  vector<int> temp;
  REP(i, 1, (v.size() + 1) / 2) {
    temp.push_back(v[i - 1] + v[v.size() - i]);
  }
  return game(temp);
}

void solve() {
  int N; cin >> N;
  vector<int> v(N, 0);
  for(auto &i : v) cin >> i;
  v = game(v);
  if(v.front() > v.back()) cout << "Alice\n";
  else cout << "Bob\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  REP(i, 1, T) {
    cout << "Case #" << i << ": ";
    solve();
  }
}