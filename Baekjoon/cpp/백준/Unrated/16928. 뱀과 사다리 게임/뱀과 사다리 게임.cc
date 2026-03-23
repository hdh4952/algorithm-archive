#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<bool> vis(101, 0);
  map<int, int> ladder;
  int N, M;
  cin >> N >> M;

  int x, y;
  while(N--) {
    cin >> x >> y;
    ladder[x] = y;
  }

  int u, v;
  while(M--) {
    cin >> u >> v;
    ladder[u] = v;
  }

  queue<int> q;  // {now, cnt}
  int answer = 0;
  q.emplace(1);
  while(!q.empty()) {
    answer++;
    size_t qsize = q.size();
    while(qsize--) {
      auto now = q.front();
      q.pop();

      for(int i=1 ; i<7 ; i++) {
        int nxt = now + i;
        if(nxt == 100) {
          cout << answer;
          return 0;
        }
        if(ladder.find(nxt) != ladder.end()) nxt = ladder[nxt];
        if(nxt > 100 || vis[nxt]) continue;
        vis[nxt] = true;
        q.emplace(nxt);
      }
    }
  }
}