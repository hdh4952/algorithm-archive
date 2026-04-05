#include <bits/stdc++.h>
using namespace std;

map<string, int> m{
  {"Franklin", 100},
  {"Grant", 50},
  {"Jackson", 20},
  {"Hamilton", 10},
  {"Lincoln", 5},
  {"Washington", 1}
};

void solve() {
  int ret = 0;

  string line;
  getline(cin, line);
  stringstream ss(line);
  string word;
  while (ss >> word) {
    ret += m[word];
  }

  cout << "$" << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  string dummy;
  getline(cin, dummy);
  while (t--) solve();

}