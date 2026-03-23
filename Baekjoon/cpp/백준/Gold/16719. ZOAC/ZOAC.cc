#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
  if(s.empty())
    return;
  if(s.size() == 1) {
    cout << s << "\n";
    return;
  }
  for(int i=0 ; i<s.size() - 1 ; i++) {
    if(s[i] > s[i+1]) {
      solve(s.substr(0, i) + s.substr(i+1, s.size()-i-1));
      cout << s << "\n";
      return;
    }
  }
  solve(s.substr(0, s.size()-1));
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  solve(s);
}