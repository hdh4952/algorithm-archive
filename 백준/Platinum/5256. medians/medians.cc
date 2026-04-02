#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int N; cin >> N;
  vector<int> B(N), ans;
  vector<bool> check(2*N, false);
  for (auto &i : B) cin >> i;

  check[B[0]] = true;
  ans.push_back(B[0]);
  int left = 1, right = 2*N-1;
  for (int i=1 ; i<N ; i++) {
    if (B[i-1] == B[i]) {
      while (check[left]) { ++left; }
      ans.push_back(left);
      check[left] = true;
      while (check[right]) { --right; }
      ans.push_back(right);
      check[right] = true;
    } else if (B[i-1] < B[i]) {
      int cnt = 2;
      if (!check[B[i]]) {
        ans.push_back(B[i]);
        check[B[i]] = true;
        --cnt;
      }
      for (int j=0 ; j<cnt; j++) {
        while (check[right]) { --right; }
        ans.push_back(right);
        check[right] = true;
      }
    } else {
      int cnt = 2;
      if (!check[B[i]]) {
        ans.push_back(B[i]);
        check[B[i]] = true;
        --cnt;
      }
      for (int j=0 ; j<cnt; j++) {
        while (check[left]) { ++left; }
        ans.push_back(left);
        check[left] = true;
      }
    }
  }

  for (const auto& i : ans) cout << i << " ";  
}
