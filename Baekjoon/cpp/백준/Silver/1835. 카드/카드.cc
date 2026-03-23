#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  queue<int> q;
  REP(i, 1, N) q.push(i);
  vector<int> v(N);
  vector<int> answer(N);
  int idx = 0;
  int n = 1;
  while(!q.empty()) {
    REP(i, 1, n) {
      q.push(q.front());
      q.pop();
    }
    n++;
    v[idx++] = q.front();
    q.pop();
  }
  REP(i, 1, N) answer[v[i-1] - 1] = i;
  for(auto i : answer) cout << i << " ";
}