#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

string solve() {
  vector<int> v(3, 0);
  REP(i, 0, 2) cin >> v[i];
  sort(v.begin(), v.end());
  if (v[2] * v[2] == v[0] * v[0] + v[1] * v[1]) return "yes";
  return "no";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  REP(i, 1, n) {
    cout << "Scenario #" << i << ":\n";
    cout << solve() << "\n\n";
  }
}