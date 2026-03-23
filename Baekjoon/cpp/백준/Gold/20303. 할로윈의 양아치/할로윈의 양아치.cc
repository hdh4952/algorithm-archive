#include <bits/stdc++.h>
#define MAX 50000
using namespace std;

int find(vector<int> &child, int a) {
  return child[a] = a == child[a] ? a : find(child, child[a]);
}

void merge(vector<int> &candy, vector<int> &child, vector<int> &connect,int a, int b) {
  int x = find(child, a), y = find(child, b);
  if(x == y) return;
  candy[x] += candy[y];
  candy[y] = 0;
  connect[x] += connect[y];
  connect[y] = 0;
  child[y] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;

  vector<int> child(N+1), candy(N+1), connect(N+1, 1);
  iota(child.begin(), child.end(), 0);
  for(int i=1 ; i<=N ; i++)
    cin >> candy[i];

  while(M--) {
    int a, b;
    cin >> a >> b;
    if(find(child, a) == find(child, b)) continue;
    merge(candy, child, connect, a, b);
  }

  vector<pair<int, int>> vp; // {사탕수, 아이들수}
  for(int i=1 ; i<=N ; i++) {
    if(connect[i])
      vp.push_back({candy[i], connect[i]});
  }

  vector<vector<int>> dp(vp.size() + 1, vector<int>(K, 0));
  for(int i=1 ; i<=vp.size() ; i++) {
    for(int k=1 ; k<K ; k++) {
      if(vp[i-1].second > k) dp[i][k] = dp[i-1][k];
      else dp[i][k] = max(dp[i-1][k], vp[i-1].first + dp[i-1][k - vp[i-1].second]);
    }
  }

  cout << dp[vp.size()][K-1];
}