#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, L, K;
  cin >> N >> L >> K;
  vector<pair<int, int>> sub(N);
  vector<int> score;
  for(auto &[a, b] : sub) cin >> a >> b;
  for(auto [a, b] : sub) {
    if(L >= b) score.push_back(140);
    else if(L >= a) score.push_back(100);
    else score.push_back(0);
  }

  sort(score.begin(), score.end(), greater<>());
  cout << accumulate(score.begin(), score.begin() + K, 0);
}