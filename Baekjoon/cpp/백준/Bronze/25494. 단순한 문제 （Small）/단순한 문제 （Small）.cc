#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int memo[61][61][61];

void init() {
  REP(i, 1, 60) {
    REP(j, 1, 60) {
      REP(k, 1, 60) {
        if(i % j == j % k && j % k == k % i)
          memo[i][j][k] = 1;
      }
    }
  }
}

void solve() {
  int a, b, c, answer = 0;
  cin >> a >> b >> c;
  REP(i, 1, a) {
    REP(j, 1, b) {
      REP(k, 1, c) {
        if(memo[i][j][k]) answer++;
      }
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  int T;
  cin >> T;
  while(T--) solve();
}