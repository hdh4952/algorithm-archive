#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

vector<char> trans(vector<char> v) {
  deque<char> dq;
  bool state = false;
  if(v.size() & 1) state = true;
  reverse(v.begin(), v.end());
  for(auto ch : v) {
    if(!state)
      dq.push_back(ch);
    else
      dq.push_front(ch);

    state = !state;
  }
  vector<char> ans;
  while(!dq.empty()) {
    ans.push_back(dq.front());
    dq.pop_front();
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X; cin >> X;
  int cnt = 0;
  vector<char> v;
  string s; cin >> s;
  for(auto ch : s) v.push_back(ch);
  vector<char> temp = v;
  while(true) {
    cnt++;
    temp = trans(temp);
    if(temp == v) break;
  }

  X %= cnt;
  REP(i, 1, X)
    v = trans(v);
  for(auto ch : v) cout << ch;
}