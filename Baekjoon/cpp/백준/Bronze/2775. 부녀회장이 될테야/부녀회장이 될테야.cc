#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int arr[15][15];

void init();
void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  int T;
  cin >> T;
  while(T--) solve();
}

void init() {
  REP(i, 1, 14) arr[0][i] = i;
  REP(i, 1, 14)
    REP(j, 1, 14)
      arr[i][j] = arr[i][j-1] + arr[i-1][j];
}

void solve() {
  int k, n;

  cin >> k >> n;

  cout << arr[k][n] << "\n";
}