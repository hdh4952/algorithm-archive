#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, a, sum = 0, bonus, answer = 0, st;
  vector<int> container;

  cin >> n;
  REP(i, 1, n) {
    cin >> a;
    container.push_back(a);
  }
  sum = accumulate(container.begin(), container.end(), 0);
  bonus = sum % n;
  st = sum / n;

  REP(i, 0, n - 1) {
    if (container[i] > st) {
      if (bonus) {
        bonus--;
        answer += container[i] - st - 1;
      } else answer += container[i] - st;
    }
  }

  cout << answer;
}