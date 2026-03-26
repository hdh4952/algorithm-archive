#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) cin >> i;
  reverse(arr.begin(), arr.end());
  vector<int> fail(n, 0);
  for (int i=1, j=0 ; i<n ; i++) {
    while (j > 0 && arr[i] != arr[j]) {
      j = fail[j-1];
    }
    if (arr[i] == arr[j]) {
      fail[i] = ++j;
    }
  }

  int max_idx = 0, max_fail = 0;
  for (int i=0 ; i<n ; i++) {
    if (max_fail < fail[i]) {
      max_fail = fail[i];
      max_idx = i;
    }
  }

  cout << n - max_idx - 1 << " " << max_idx - max_fail + 1;
}
