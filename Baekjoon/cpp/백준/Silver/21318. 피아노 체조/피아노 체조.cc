#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, Q, x, y;
  cin >> N;

  vector<int> diff(N + 1, 0), sum(N+1, 0);
  REP(i, 1, N) cin >> diff[i];
  REP(i, 1, N - 1) if(diff[i] > diff[i+1]) sum[i] = 1;
  REP(i, 1, N) sum[i] += sum[i-1];

  cin >> Q;
  REP(i, 1, Q) {
    cin >> x >> y;
    if(x == y) cout << "0\n";
    else cout << sum[y-1] - sum[x-1] << "\n";
  }
}