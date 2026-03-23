#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<int> v(N, 0);
  char t;
  REP(i, 0, N-2) cin >> v[i] >> t;
  cin >> v[N-1];
  REP(k, 1, K) {
    REP(i, 0, N-k-1) v[i] = v[i+1] - v[i];
    v.pop_back();
  }
  string ans;
  for(auto i : v) ans += to_string(i) + ',';
  ans.pop_back();
  cout << ans;
}