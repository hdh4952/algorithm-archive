#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll findParent(ll a) {
  for (ll i = 2; i * i <= a; i++)
    if (a % i == 0) return a / i;
  return 1;
}

ll solve(ll a, ll b) {
  if (a == b) return a;
  if (a < b) swap(a, b);
  return solve(b, findParent(a));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll a, b;
  cin >> a >> b;
  cout << solve(a, b);
}