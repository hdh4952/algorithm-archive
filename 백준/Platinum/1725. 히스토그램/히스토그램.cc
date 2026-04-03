#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int N; cin >> N;
  vector<ll> arr(N);
  for (auto &i : arr) cin >> i;

  stack<pair<ll, int>> s;
  ll ans = 0;
  for (int i=0 ; i<N ; i++) {
    if (s.empty() || s.top().first < arr[i]) {
      s.push({arr[i], i});
      continue;
    }
    
    int cmp = -1;
    while (!s.empty() && s.top().first >= arr[i]) {
      auto [h, idx] = s.top();
      cmp = idx;
      s.pop();
      ans = max(ans, h*(i-idx));
    }

    if (cmp != -1) {
      s.push({arr[i], cmp});
    }
  }

  while (!s.empty()) {
    auto [h, idx] = s.top();
    s.pop();
    ans = max(ans, h*(N - idx));
  }

  cout << ans;
}