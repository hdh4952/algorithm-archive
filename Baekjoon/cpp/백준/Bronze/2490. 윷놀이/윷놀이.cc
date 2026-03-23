#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> v(4, 0);
  vector<char> ans {'D', 'C', 'B', 'A', 'E'};
  int cnt;

  REP(t, 1, 3) {
    REP(i, 0, 3) cin >> v[i];
    cnt = count(v.begin(), v.end(), 1);
    cout << ans[cnt] << "\n";
  }
}