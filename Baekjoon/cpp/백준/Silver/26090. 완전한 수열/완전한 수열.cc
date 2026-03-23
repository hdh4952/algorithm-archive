#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<int> prime;

void primeInit() {
  vector<int> v(1000001);
  vector<bool> isPrime(1000001, true);
  isPrime[0] = isPrime[1] = false;
  for(int i=2 ; i<=1000000 ; i++) {
    if(!isPrime[i]) continue;
    for(int j=i+i ; j<=1000000 ; j+=i) isPrime[j] = false;
  }
  REP(i, 2, 1000000) if(isPrime[i]) prime.push_back(i);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  primeInit();
  int N, ans = 0;
  cin >> N;
  vector<int> a(N+1);
  vector<int> sum(N+1, 0);
  REP(i, 1, N) cin >> a[i];
  REP(i, 1, N) sum[i] = a[i] + sum[i-1];
  for(auto p : prime) {
    if(p > N) break;
    REP(i, p, N) {
      if(find(prime.begin(), prime.end(), sum[i] - sum[i-p]) != prime.end()) ans++;
    }
  }
  cout << ans;
}