#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n) {
    if (n == 0) break;
    bool isConflict = false;
    vector<pair<int, int>> times(n);
    for (auto &[a, b] : times) {
      string s; cin >> s;
      a = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
      b = stoi(s.substr(6, 2)) * 60 + stoi(s.substr(9, 2));
    }

    sort(times.begin(), times.end());
    for (int i=1 ; i<n ; i++) {
      if (times[i-1].second <= times[i].first) continue;
      isConflict = true;
      break;
    }

    if (isConflict) cout << "conflict\n";
    else cout << "no conflict\n";
  }

}