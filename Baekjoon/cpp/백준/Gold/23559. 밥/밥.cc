#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, X;
  cin >> N >> X;
  vector<pair<int, int>> v;
  int A, B;
  REP(i, 1, N) {
    cin >> A >> B;
    v.emplace_back(A, B);
  }

  sort(v.begin(), v.end(), [](auto a, auto b) {
    return (a.first - a.second) > (b.first - b.second);
  });

  X -= 1000 * N;
  int cnt = X / 4000, answer = 0;
  for(auto [a, b] : v) {
    if(a - b > 0 && cnt) {
      answer += a;
      cnt--;
    } else {
      answer += b;
    }
  }

  cout << answer;
}