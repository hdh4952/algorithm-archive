#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s;
  vector<char> v{'H', 'I', 'A', 'R', 'C'};
  vector<int> cnt(5, 0);

  cin >> n >> s;
  for(auto ch : s) {
    auto it = find(v.begin(), v.end(), ch);
    if(it == v.end()) continue;
    cnt[distance(v.begin(), it)]++;
  }

  cout << *min_element(cnt.begin(), cnt.end());
}