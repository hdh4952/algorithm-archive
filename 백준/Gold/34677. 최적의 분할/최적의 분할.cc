#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3001;
vector<int> A(MAX_N);
vector<int> B(MAX_N);
vector<int> dp(MAX_N);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  iota(dp.begin(), dp.end(), 1);
  int n;
  cin >> n;
  for (int i=0 ; i<n ; i++) cin >> A[i];
  for (int i=0 ; i<n ; i++) cin >> B[i];

  for (int i=0 ; i<n ; i++) {
    int min_A = MAX_N, idx1 = i;
    int min_B = MAX_N, idx2 = i;
    for (int j=i ; j<n ; j++) {
      if (A[j] < min_A) {
        min_A = A[j];
        idx1 = j;
      }

      if (B[j] < min_B) {
        min_B = B[j];
        idx2 = j;
      }

      if (idx1 == idx2) {
        dp[j] = min(dp[j], i==0 ? 1 : dp[i-1] + 1);
      }
    }
  }

  cout << dp[n-1];
}