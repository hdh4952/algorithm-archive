#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
int N;
vector<pair<int, int>> adj[100'001];

int minCost(int now, int pre, int cmp) {
  bool isLeaf = true;
  int sum = 0;
  for (auto [nxt, cost] : adj[now]) {
    if (nxt == pre) continue;
    isLeaf = false;
    sum += minCost(nxt, now, cost);
  }

  if (isLeaf) return cmp;
  return min(cmp, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i=0 ; i<N-1 ; i++) {
    int A, B, V; cin >> A >> B >> V;
    adj[A].push_back({B, V});
    adj[B].push_back({A, V});
  }

  cout << minCost(1, -1, INF);

}