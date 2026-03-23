#include <bits/stdc++.h>
#define MAX 50000
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;
  cin >> k;
  vector<int> weight(k + 1, 0);
  for(int i=1 ; i<=k ; i++)
    cin >> weight[i];

  vector<vector<bool>> dp(k+1, vector<bool>(MAX, false));
  for(int idx=1 ; idx<=k ; idx++) {
    for(int w=1 ; w<=MAX ; w++) {
      dp[idx][w] = (weight[idx] == w) || dp[idx-1][w] || dp[idx-1][abs(w - weight[idx])] || dp[idx-1][w + weight[idx]];
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int w;
    cin >> w;
    if(dp[k][w]) cout << "Y ";
    else cout << "N ";
  }
}