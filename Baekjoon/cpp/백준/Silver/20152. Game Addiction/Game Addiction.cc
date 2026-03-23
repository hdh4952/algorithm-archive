#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

ll solve(int n) {
  vector<vector<ll>> sum(n+1, vector<ll>(n+1, 0));
  sum[0][1] = 1;
  REP(i, 1, n) {
    REP(j, i, n) {
      sum[i][j] = sum[i-1][j] + sum[i][j-1];
    }
  }

  return sum[n][n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int H, N; cin >> H >> N;
  int gap = abs(H - N);
  cout << solve(gap + 1);
}