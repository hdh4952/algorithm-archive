#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
int answer;

void init() {
  string s = "quack";
  for (auto ch : s) m[ch] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  for (auto ch : s) {
    m[ch]++;
    if (ch != 'q') {
      if (ch == 'u') m['q']--;
      else if (ch == 'a') m['u']--;
      else if (ch == 'c') m['a']--;
      else if (ch == 'k') m['c']--;
    }
    answer = max(answer, m['q'] + m['u'] + m['a'] + m['c']);
    if (m['q'] < 0 || m['u'] < 0 || m['a'] < 0 || m['c'] < 0) {
      cout << "-1";
      return 0;
    }
  }
  if(m['q'] || m['u'] || m['a'] || m['c']) cout << "-1";
  else cout << answer;
}