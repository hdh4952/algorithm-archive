#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  vector<ll> A(N), B(N);
  REP(i, 0, N-1) {
    cin >> A[i] >> B[i];
    ll c = gcd(A[i], B[i]);
    if(c != 1) {
      A[i] /= c;
      B[i] /= c;
    }
  }
  ll a = A[0], b = B[0];
  for(auto i : A) a = gcd(a, i);
  for(auto i : B) b = lcm(b, i);
  cout << a << " " << b;
}