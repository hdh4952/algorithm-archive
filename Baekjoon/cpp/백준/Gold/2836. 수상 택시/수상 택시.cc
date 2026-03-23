#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

struct Dist {
  ll left;
  ll right;

  bool operator<(const Dist d) const {
    return this->left > d.left;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, M; cin >> N >> M;
  ll a, b;
  priority_queue<Dist> pq;
  vector<Dist> v;

  REP(i, 1, N) {
    cin >> a >> b;
    if(a > b) pq.push({b,a});
  }
  a = b = 0;
  while(!pq.empty()) {
    if(a == 0 && b == 0) {
      a = pq.top().left;
      b = pq.top().right;
    } else {
      if(b > pq.top().left) b = max(b, pq.top().right);
      else {
        v.push_back({a, b});
        a = pq.top().left;
        b = b = pq.top().right;
      }
    }
    pq.pop();
  }

  if(!(a == 0 && b == 0)) v.push_back({a, b});
  ll start = 0, answer = 0;
  for(auto [x, y] : v) {
    answer += y - start + y - x;
    start = x;
  }
  cout << answer + M - start;
}