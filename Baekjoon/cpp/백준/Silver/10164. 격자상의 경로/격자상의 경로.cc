#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

ll f(int n) {
  if (n <= 1) return 1;
  return n * f(n - 1);
}

ll solve(int right, int down) {
  int a = max(right, down), b = min(right, down);
  ll ans = 1;
  REP(i, a + 1, right + down) ans *= i;
  return ans / f(b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;
  if (K) {
    int tempN = (K % M == 0 ? K / M : K / M + 1), tempM = (K % M == 0 ? M : K % M);
    ll ans = solve(tempM - 1, tempN - 1);
    ans *= solve(M - tempM, N - tempN);
    cout << ans;
  } else cout << solve(M - 1, N - 1);
}