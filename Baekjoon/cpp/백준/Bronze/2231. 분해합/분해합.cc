#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int check(int N) {
  int sum = N;
  while(N) {
    sum += N % 10;
    N /= 10;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  REP(i, 1, N) {
    if(check(i) == N) {
      cout << i;
      return 0;
    }
  }
  cout << "0";
}