#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  vector<int> H(N);
  int answer = 0;
  REP(i, 0, N-1) cin >> H[i];
  REP(i, 0, N-2) {
    answer += (H[i] + H[i+1]) * (H[i] + H[i+1]) + abs(H[i] - H[i+1]) * abs(H[i] - H[i+1]);
  }
  cout << answer;
}