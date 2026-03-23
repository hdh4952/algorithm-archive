#include <bits/stdc++.h>
using namespace std;

int calCost(const string& lhs, const string& rhs) {
  int answer = 0;
  for(int i=0 ; i<lhs.size() ; i++)
    answer += abs(lhs[i] - rhs[i]) * abs(lhs[i] - rhs[i]);
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<string> v(N);
  vector<vector<int>> cost(N, vector<int>(N));
  for(auto &i : v)
    cin >> i;

  for(int i=0 ; i<N-1 ; i++)
    for(int j=i+1 ; j<N ; j++)
      cost[i][j] = cost[j][i] = calCost(v[i], v[j]);

  int a, b;
  cin >> a >> b;
  a--;
  b--;
  if(a == b) {
    cout << "0";
    return 0;
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
  vector<int> answer(N, 0);
  vector<bool> vis(N, false);
  vis[a] = true;

  while(!answer[b]) {
    for(int i=0 ; i<N ; i++) {
      if(vis[i]) continue;
      pq.emplace(cost[a][i] + answer[a], a, i);
    }

    int nxt = a;
    while(nxt == a) {
      auto [c, s, e] = pq.top();
      pq.pop();
      if(vis[e])
        continue;
      vis[e] = true;
      answer[e] = c;
      nxt = e;
    }
    a = nxt;
  }

  cout << answer[b];
}