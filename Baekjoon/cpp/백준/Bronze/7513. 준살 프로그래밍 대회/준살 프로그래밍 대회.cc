#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

void solve() {
  int m, n, passwordInfo, idx;
  string word;
  vector<string> words;

  cin >> m;
  REP(i, 1, m) {
    cin >> word;
    words.push_back(word);
  }

  cin >> n;
  while(n--) {
    cin >> passwordInfo;
    REP(i, 1, passwordInfo) {
      cin >> idx;
      cout << words[idx];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase;
  cin >> testcase;
  REP(i, 1, testcase) {
    cout << "Scenario #" << i << ":\n";
    solve();
    cout << "\n";
  }
}