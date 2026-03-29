#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;
  string S; cin >> S;
  vector<char> wants{'H', 'I', 'A', 'R', 'C'};
  vector<int> cnt(5, 0);
  for (auto ch : S) {
    auto iter = find(wants.begin(), wants.end(), ch);
    if (iter != wants.end()) {
      ++cnt[iter - wants.begin()];
    }
  } 

  cout << *min_element(cnt.begin(), cnt.end());
}
