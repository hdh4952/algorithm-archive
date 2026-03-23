#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M; cin >> N >> M;
  int a, b, c;
  vector<int> light(N+1, 0);

  REP(i, 1, N) cin >> light[i];
  REP(i, 1, M) {
    cin >> a >> b >> c;
    switch (a) {
      case 1:
        light[b] = c;
        break;
      case 2:
        REP(x, b, c) light[x] = !light[x];
        break;
      case 3:
        REP(x, b, c) light[x] = 0;
        break;
      case 4:
        REP(x, b, c) light[x] = 1;
        break;
      default:
        break;
    }
  }

  REP(i, 1, N) cout << light[i] << " ";
}