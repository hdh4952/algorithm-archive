#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(201, vector<int>(201, 0));

int solve(int N, int K) {
  if(K == 1)
    return 1;
  if(memo[N][K]) return memo[N][K];
  int answer = 0;
  for(int i=0 ; i<=N ; i++) {
      answer += solve(N - i, K - 1);
      answer %= 1'000'000'000;
  }

  return memo[N][K] = answer % 1'000'000'000;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  cout << solve(N, K);
}