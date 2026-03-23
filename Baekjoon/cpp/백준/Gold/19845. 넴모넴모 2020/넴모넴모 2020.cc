#include <bits/stdc++.h>
#define MAX 250'000
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll N, Q;
  cin >> N >> Q;
  vector<ll> a(MAX + 1, 0);
  for(int i=1 ; i<=N ; i++)
      cin >> a[i];
  while(Q--) {
      ll x, y;
      cin >> x >> y;
      if(a[y] < x) {
          cout << "0\n";
          continue;
      }
      ll s = 0, e = N + 1;
      while(s + 1 < e) {
          ll mid = (s + e) / 2;
          if(a[mid] >= x) s = mid;
          else e = mid;
      }
      cout << a[y] - x + e - y << "\n";
  }
}