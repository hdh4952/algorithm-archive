#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string S; cin >> S;
  stack<pair<int, int>> s;
  int cnt = 0;
  for (int i=0 ; i<S.length() ; i++) {
    if (S[i] == '(') {
      --cnt;
      s.push({cnt, S[i-1] - '0'});
      cnt = 0;
    } else if(S[i] == ')') {
      auto [pre_cnt, mul] = s.top();
      s.pop();
      cnt = pre_cnt + mul * cnt;
    } else {
      ++cnt;
    }
  }

  cout << cnt;
}