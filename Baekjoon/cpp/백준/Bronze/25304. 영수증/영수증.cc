#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X, N, a, b;
  cin >> X >> N;
  REP(i, 1, N) {
    cin >> a >> b;
    X -= a * b;
  }

  if(X == 0) cout << "Yes";
  else cout << "No";
}