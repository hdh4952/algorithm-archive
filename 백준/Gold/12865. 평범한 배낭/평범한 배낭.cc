#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int N, K; cin >> N >> K;
  vector<int> value(N+1, 0);
  vector<int> weight(N+1, 0);
  for (int i=1 ; i<=N ; i++) {
    cin >> weight[i] >> value[i];
  }

  vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
  for (int i=1 ; i<=N ; i++) {
    for (int j=0 ; j<=K ; j++) {
      if (j < weight[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
    }
  }

  cout << dp[N][K];
}