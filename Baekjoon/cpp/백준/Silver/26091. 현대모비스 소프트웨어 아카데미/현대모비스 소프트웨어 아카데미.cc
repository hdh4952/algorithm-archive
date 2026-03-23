#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, ans = 0;
  cin >> N >> M;
  vector<int> p(N, 0);
  REP(i, 0, N-1) cin >> p[i];
  sort(p.begin(), p.end());

  int left = 0, right = N - 1;
  while(left < right) {
    if(p[left] + p[right] >= M) {
      ans++;
      left++;
      right--;
    } else left++;
  }

  cout << ans;
}