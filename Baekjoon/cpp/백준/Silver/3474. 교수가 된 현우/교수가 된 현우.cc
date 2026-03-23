#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  int N, answer;

  while(T--) {
    cin >> N;
    answer = 0;
    while(N) {
      answer += N / 5;
      N /= 5;
    }
    cout << answer << "\n";
  }
}