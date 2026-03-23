#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

vector<int> v('Z' - 'A' + 1, 0), check('Z' - 'A' +1, 0);
ll memo[50010][4];

ll nCr(int n, int r) {
  if(n < r) return 0;
  if(n == r) return 1;
  if(r == 1) return n;
  if(memo[n][r]) return memo[n][r];
  return memo[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

ll makeTeam() {
  vector<ll> temp;
  REP(i, 0, 'Z' - 'A') {
    if(!check[i]) continue;
    temp.push_back(nCr(v[i], check[i]));
  }

  ll ans = temp.front();
  REP(i, 1, temp.size() - 1) ans *= temp[i];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s, name;
  int n;
  cin >> s >> n;
  for(auto ch : s) check[ch - 'A']++;
  REP(i, 1, n) {
    cin >> name;
    v[name[0] - 'A']++;
  }

  cout << makeTeam();
}