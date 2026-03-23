#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<int> v(5001, 0);

bool isRepeat(int n) {
  vector<bool> check(10, false);
  while (n) {
    if (check[n % 10]) return true;
    check[n % 10] = true;
    n /= 10;
  }
  return false;
}

void init() {
  REP(i, 1, 5000) {
    if (!isRepeat(i)) v[i] = 1 + v[i - 1];
    else v[i] = v[i - 1];
  }
}

int solve(int n, int m) {
  return v[m] - v[n - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  init();
  int N, M;
  while (cin >> N >> M) cout << solve(N, M) << "\n";
}