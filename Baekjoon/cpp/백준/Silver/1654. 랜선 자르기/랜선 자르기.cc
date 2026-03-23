#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll K, N;
  cin >> K >> N;

  vector<ll> len(K);
  for(auto &l : len) cin >> l;

  ll s = 1, e = *max_element(len.begin(), len.end());
  while(s <= e) {
    ll mid = (s + e) / 2;
    ll sum = 0;
    for(auto l : len) {
      sum += l / mid;
    }
    if(sum >= N) s = mid + 1;
    else e = mid - 1;
  }

  cout << e;
}