#include <bits/stdc++.h>
using namespace std;

int find(int a, vector<int> &uf) {
  return uf[a] = a == uf[a] ? a : find(uf[a], uf);
}

void merge(int a, int b, vector<int> &uf) {
  uf[find(a, uf)] = find(b, uf);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
  int cnt = 0, answer = 0;

  for(int i=1 ; i<=N ; i++) {
    for(int j=1 ; j<=N ; j++) {
      char c;
      cin >> c;
      if(c == '0') continue;
      int value = ('a' <= c && c <= 'z') ? (c - 'a' + 1) : (c - 'A' + 27);
      if(i == j) {
        answer += value;
        continue;
      }
      pq.emplace(value, i, j);
    }
  }

  vector<int> uf(N+1, 0);
  iota(uf.begin(), uf.end(), 0);

  while(!pq.empty() && cnt != N - 1) {
    auto [cost, a, b] = pq.top();
    pq.pop();
    if(find(a, uf) == find(b, uf)) {
      answer += cost;
      continue;
    }
    merge(a, b, uf);
    cnt++;
  }
  if(cnt == N-1) {
    while(!pq.empty()) {
      answer += get<0>(pq.top());
      pq.pop();
    }
    cout << answer;
  }
  else cout << "-1";
}

