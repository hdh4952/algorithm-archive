#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int A, B, C;
string X, Y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> A >> B >> C >> X >> Y;
  vvi dp(Y.size() + 1, vi(X.size() + 1, 0));
  for(int i=1 ; i<=X.size() ; i++)
    dp[0][i] = B * i;
  for(int i=1 ; i<=Y.size() ; i++)
    dp[i][0] = B * i;
  for(int i=1 ; i<=Y.size() ; i++) {
    for(int j=1 ; j<=X.size() ; j++) {
      dp[i][j] = max(dp[i-1][j] + B, dp[i][j-1] + B);
      dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (X[j-1] == Y[i-1] ? A : C));
    }
  }
//  for(int i=0 ; i<=Y.size() ; i++) {
//    for(int j=0 ; j<=X.size() ; j++) {
//      cout << dp[i][j] << " ";
//    }
//    cout << "\n";
//  }
  cout << dp[Y.size()][X.size()];
}