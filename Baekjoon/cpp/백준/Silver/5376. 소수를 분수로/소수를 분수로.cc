#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll mul(ll a, ll b) {
  ll ans = a;
  REP(i, 2, b) ans *= a;
  return ans;
}

void solve() {
  string s;
  cin >> s;

  bool state = false;
  string a, b, c;
  REP(i, 2, s.size() - 1) {
    if(s[i] == ')') break;
    if(s[i] == '(') {
      state = true;
      continue;
    }
    a += s[i];
    if(!state) b += s[i];
    else c += s[i];
  }
  ll p = 0, q = 0;
  if(c.empty()) {
    p = stoll(b);
    q = mul(10, b.size());
  } else {
    string tmp;
    if(b.empty()) p = stoll(a);
    else p = stoll(a) - stoll(b);
    REP(i, 1, c.size()) tmp += '9';
    REP(i, 1, b.size()) tmp += '0';
    q = stoll(tmp);
  }
  ll r = gcd(p, q);
  cout << p / r << "/" << q / r << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}