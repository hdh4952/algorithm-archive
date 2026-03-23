#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll answer = 0, cmp = 0;
  int N, M, x, y, u, v, c;
  vector<int> location(200001, 0);
  vector<tuple<int, int, int>> road;
  priority_queue<tuple<int, int, int>> pq;
  cin >> N >> M;

  REP(i, 1, N) {
    cin >> x >> y;
    location[i] = y;
  }

  REP(i, 1, M) {
    cin >> u >> v >> c;
    road.emplace_back(min(location[u], location[v]), max(location[u], location[v]), c);
  }

  sort(road.begin(), road.end(), [](auto a, auto b) { return get<1>(a) > get<1>(b); });
  for (auto [left, right, cost] : road) {
    if (pq.empty() || get<0>(pq.top()) <= right) {
      cmp += cost;
      pq.push({left, right, cost});
    } else {
      while (!pq.empty() && get<0>(pq.top()) > right) {
        cmp -= get<2>(pq.top());
        pq.pop();
      }
      cmp += cost;
      pq.push({left, right, cost});
    }
    answer = max(answer, cmp);
  }

  cout << answer;
}