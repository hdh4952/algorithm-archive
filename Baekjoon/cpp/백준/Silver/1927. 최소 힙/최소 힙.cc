#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<>> pq;
  int x;
  REP(i, 1, N) {
    cin >> x;
    if (x == 0) {
      if (pq.empty()) cout << "0\n";
      else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    } else pq.push(x);
  }
}