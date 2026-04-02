#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;
  vector<int> h(N), d(N+1);
  for (auto &i : h) cin >> i;
  while (M--) {
    int a, b, k; cin >> a >> b >> k;
    d[a-1] += k;
    d[b] -= k;
  }

  for (int i=1 ; i<N ; i++) {
    d[i] += d[i-1];
  }

  for (int i=0 ; i<N ; i++) {
    cout << h[i] + d[i] << " ";
  }
}
