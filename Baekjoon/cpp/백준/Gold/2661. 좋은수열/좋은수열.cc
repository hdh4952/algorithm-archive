#include <bits/stdc++.h>
using namespace std;

bool flag;
map<string, bool> m;
bool checkString(const string& s) {
  for(int len=1 ; len<=s.size()/2 ; len++) {
    for(int i=0 ; i<s.size()-2*len+1 ; i++) {
      if(s.substr(i, len) == s.substr(i+len, len)) return false;
    }
  }
  return true;
}

void solve(int now, int n, string s) {
  if(now == n) {
    cout << s;
    flag = true;
    return;
  }

  for(auto ch : {'1', '2', '3'}) {
    if(s.back() == ch) continue;
    if(checkString(s + ch))
      solve(now+1, n, s + ch);
    if(flag) return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  solve(0, n, "");
}