#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<int> memo(10001, 0);
int N, M;

int cal(int n) {
  if(n < M) return 1;
  if(n == M) return 2;
  if(memo[n]) return memo[n];
  return memo[n] = (cal(n - 1) + cal(n - M)) % 1000000007;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  cout << cal(N);
}