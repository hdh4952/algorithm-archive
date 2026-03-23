#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s; cin >> s;
  int cnt = 0;
  for(auto ch : s) {
    if(ch == '@') cnt++;
    if(ch == '(') {
      cout << cnt << " ";
      cnt = 0;
    }
  }
  cout << cnt;
}