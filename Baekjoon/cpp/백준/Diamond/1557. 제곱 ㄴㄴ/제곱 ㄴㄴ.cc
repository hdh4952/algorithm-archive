#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> isPrime(50001, true);
vector<int> mu(50001, -1);

void init() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= 50000; i++) {
    if (isPrime[i])
      for (int j = i + i; j <= 50000; j += i)
        isPrime[j] = false;
  }

  mu[1] = 1;
  for(int i=2 ; i<50000 ; i++) {
    for(int j=2 ; j<50000 ; j++) {
      if(isPrime[j]) {
        if(i * j > 50000) break;
        if(i % j == 0) {
          mu[i * j] = 0;
          break;
        }
        mu[i * j] = mu[i] * mu[j];
      }
    }
  }
}

pair<bool, ll> nono(ll n) {
  bool isNono = true;
  ll sum = 0;
  for(int i=1 ; i*i<=n ; i++) {
    if(isPrime[i] && n % (i*i) == 0) isNono = false;
    sum += n / (i*i) * mu[i];
  }
  return {isNono, sum};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  init();
  ll K;
  cin >> K;
  ll s = 1, e = 2 * K;
  while (s <= e) {
    ll mid = (s + e) / 2;
    auto [isNoNo, idx] = nono(mid);
    if (isNoNo && idx == K) {
      cout << mid;
      break;
    }
    if (idx < K) s = mid + 1;
    else e = mid - 1;
  }
}