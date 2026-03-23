#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<char> temp;

void print(int now, int size, vector<int> v) {
  if(now == size) {
    for(auto ch : temp) cout << ch;
    cout << "\n";
    return;
  }
  REP(i, 0, 'z' - 'a') {
    if(!v[i]) continue;
    v[i]--;
    temp.push_back(char('a' + i));
    print(now + 1, size, v);
    temp.pop_back();
    v[i]++;
  }
}

void anagram(const string& str) {
  vector<int> v('z' - 'a' + 1, 0);
  for(auto ch : str) v[ch - 'a']++;
  print(0, str.size(), v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  string str;
  cin >> N;
  while(N--) {
    cin >> str;
    anagram(str);
  }
}