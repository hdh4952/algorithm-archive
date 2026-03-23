#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll A, B, C; cin >> A >> B >> C;
  if(A + B >= 2 * C) cout << A + B - 2 * C;
  else cout << A + B;
}