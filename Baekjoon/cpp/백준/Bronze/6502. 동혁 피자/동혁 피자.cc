#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

void solve(int r, int w, int l) {
  if(4 * r * r >= w * w + l * l) cout << " fits on the table.\n";
  else cout << " does not fit on the table.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, w, l, idx = 1;
    while(cin >> r) {
      if(r == 0) break;
      cin >> w >> l;
      cout << "Pizza " << idx++;
      solve(r, w, l);
    }
}