#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K, M; cin >> N >> K >> M;
  deque<int> dq;
  REP(i, 1, N) dq.push_back(i);
  bool  opposite = false;
  int cnt = 0;
  while(!dq.empty()) {
    if(!opposite) {
      REP(i, 1, K-1) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
      cout << dq.front() << '\n';
      dq.pop_front();
    } else {
      REP(i, 1, K-1) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      cout << dq.back() << '\n';
      dq.pop_back();
    }
    if(++cnt % M == 0) opposite = !opposite;
  }
}