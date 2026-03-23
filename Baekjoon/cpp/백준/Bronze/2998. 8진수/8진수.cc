#include <bits/stdc++.h>
using namespace std;

map<string, char> m;

void init() {
  vector<string> v = {"000", "001", "010", "011", "100", "101", "110", "111"};
  int idx = 0;
  for(const auto& s : v) m[s] = char('0' + idx++);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  init();
  string str; cin >> str;
  string answer;

  int leftPad = 3 - (str.size() % 3);
  if(leftPad != 3) while(leftPad--) str = "0" + str;
  for(int i=0 ; i<str.size() ; i+=3) {
    string s = str.substr(i, 3);
    answer += m[s];
  }

  cout << answer;
}