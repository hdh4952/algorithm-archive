#include <bits/stdc++.h>
#define MAX 200'000
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  if(N >= K) {
    cout << N - K;
    return 0;
  }

  vector<bool> vis(MAX, false);
  deque<pair<int, int>> dq;
  dq.push_back({N, 0});

  while(!dq.empty()) {
    auto [now, time] = dq.front();
    dq.pop_front();
    if(now == K) {
      cout << time;
      break;
    }
    if(now * 2 < MAX && !vis[now * 2]) {
      vis[now * 2] = true;
      dq.push_front({now * 2, time});
    }
    if(now + 1 < MAX && !vis[now + 1]) {
      vis[now + 1] = true;
      dq.push_back({now + 1, time + 1});
    }
    if(now - 1 >= 0 && !vis[now - 1]) {
      vis[now - 1] = true;
      dq.push_back({now - 1, time + 1});
    }
  }
}