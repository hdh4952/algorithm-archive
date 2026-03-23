#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, b, a, cost, answer = 0;
  vector<int> present;
  stack<int> s;

  cin >> n >> b >> a;
  REP(i, 1, n) {
    cin >> cost;
    present.push_back(cost);
  }

  sort(present.begin(), present.end());

  REP(i, 0, n - 1) {
    if (b >= present[i]) {
      s.push(present[i]);
      b -= present[i];
      answer++;
    } else {
      if (a > 0) {
        a--;
        while (!s.empty() && a > 0 && b < present[i] / 2) {
          b += s.top() / 2;
          s.pop();
          a--;
        }
        if (b >= present[i] / 2) {
          b -= present[i] / 2;
          answer++;
        } else break;
      } else break;
    }
  }

  cout << answer;
}