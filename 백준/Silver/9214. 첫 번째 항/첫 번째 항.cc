#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
  while (~s.length() & 1) {
    string nxt = "";
    for (int i=0 ; i<s.length() ; i+=2) {
      int cnt = s[i] - '0';
      for (int j=0 ; j<cnt ; j++) {
        nxt += s[i+1];
      }
    }

    if (s == nxt) break;
    s = nxt;
  }

  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int idx = 1;
  while (cin >> s) {
    if (s == "0") break;
    cout << "Test " << idx++ << ": ";
    solve(s);
  }

}