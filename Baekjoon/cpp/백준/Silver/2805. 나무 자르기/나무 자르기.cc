#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, M;
  ll s = 1, e = 1e9;
  cin >> N >> M;

  vector<ll> height(N);
  for(auto &h : height) cin >> h;

  while(s <= e) {
    ll mid = (s + e) / 2;
    ll sum = 0;
    for(auto h : height) {
      if(h > mid) sum += h - mid;
    }
    if(sum < M) e = mid - 1;
    else s = mid + 1;
  }

  cout << e;
}