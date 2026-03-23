#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, leftSide = 0, rightSide = 0, x, answer = 0;
  vector<int> w{100, 50, 20, 10, 5, 2, 1};

  cin >> n;
  while (n--) {
    cin >> x;
    if (leftSide <= rightSide) leftSide += x;
    else rightSide += x;
  }

  x = abs(leftSide - rightSide);
  for (auto i : w) {
    answer += x / i;
    x %= i;
  }

  cout << answer;
}