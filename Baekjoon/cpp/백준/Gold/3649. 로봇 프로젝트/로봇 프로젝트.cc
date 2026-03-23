#include <bits/stdc++.h>
#define MAX 100'000'000
using namespace std;

void solve(int x, int n) {
  x *= 10e6;
  vector<int> v(n);
  for(auto &i : v)
    cin >> i;
  std::sort(v.begin(), v.end());
  for(int i=0 ; i<n - 1 ; i++) {
    if(v[i] <= x / 2) {
      if(binary_search(v.begin() + i + 1, v.end(), x - v[i])) {
        cout << "yes " << v[i] << " " << x - v[i] << "\n";
        return;
      }
    }
  }
  cout << "danger\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x, n;
  while(cin >> x) {
    cin >> n;
    solve(x, n);
  }
}