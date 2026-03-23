#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int gcd(int a, int b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void solve() {
  int a, b; cin >> a >> b;
  cout << lcm(a, b) << " " << gcd(a, b) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) solve();
}