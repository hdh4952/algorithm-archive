#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, K; cin >> N >> K;
  vector<int> A(N+1, 0), sum(N+1, 0);
  map<ll, ll> m;

  REP(i, 1, N) {
    cin >> A[i];
    sum[i] = sum[i-1] + A[i];
  }

  ll answer = 0;
  for(auto i : sum) {
    ll x = i - K;
    if(m.find(x) != m.end()) answer += m[x];
    if(m.find(i) == m.end()) m[i] = 0;
    m[i]++;
  }

  cout << answer;
}