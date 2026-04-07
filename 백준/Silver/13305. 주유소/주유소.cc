#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int N; cin >> N;

  vector<ll> street(N-1);
  for (auto &i : street) cin >> i;
  
  ll ans = 0;
  int now; cin >> now;
  for (int i=0 ; i<N-1 ; i++) {
    ans += now * street[i];
    int nxt; cin >> nxt;
    if (now > nxt) {
      now = nxt;
    }
  }

  cout << ans;

}