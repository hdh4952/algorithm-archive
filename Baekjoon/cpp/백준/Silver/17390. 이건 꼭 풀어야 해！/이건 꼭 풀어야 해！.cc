#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, Q; cin >> N >> Q;
  int L, R;
  vector<int> v(N), vSum(N + 1, 0);
  for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());
  REP(i, 1, N) vSum[i] = vSum[i - 1] + v[i - 1];
  REP(i, 1, Q) {
    cin >> L >> R;
    cout << vSum[R] - vSum[L - 1] << "\n";
  }
}