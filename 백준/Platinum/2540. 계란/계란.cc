#include <bits/stdc++.h>
using namespace std;

vector<int> arr(4);

void print() {
  for (auto i : arr) cout << i << " ";
  cout << "\n";
}

void solve() {
  print();
  vector<pair<int, int>> v(4);
  for (int i=0 ; i<4 ; i++) {
    v[i] = {arr[i], i};
  }
  sort(v.begin(), v.end());
  int a = v[0].second, b = v[1].second, c = v[2].second, d = v[3].second;
  if (arr[c] == 0) return;
  int sum = arr[a] + arr[b] + arr[c];
  if (sum & 1) {
    arr[a] += 2;
    --arr[c];
    --arr[d];
    solve();
  } else {
    if (arr[a] + arr[b] >= arr[c]) {
      --arr[b];
      --arr[c];
      arr[d] += 2;
      solve();
    } else {
      arr[a] += 2;
      if (arr[b] == 0) --arr[d];
      else --arr[b];
      --arr[c];
      solve();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int K; cin >> K;
  for (auto &i : arr) cin >> i;
  solve();
}