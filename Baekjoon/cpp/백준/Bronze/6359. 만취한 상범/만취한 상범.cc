#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

void solve() {
  int n; cin >> n;
  vector<bool> isOpen(n+1, false);
  REP(i, 1, n) {
    for(int j=i ; j<=n ; j+=i) {
      isOpen[j] = !isOpen[j];
    }
  }

  cout << count(isOpen.begin(), isOpen.end(), true) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) solve();
}