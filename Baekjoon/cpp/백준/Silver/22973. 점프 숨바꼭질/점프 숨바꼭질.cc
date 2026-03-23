#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll K; cin >> K;
  K = abs(K);
  int answer = 0;
  if(K == 0) cout << "0";
  else if(K % 2 == 0) cout << "-1";
  else {
    while(K) {
      answer++;
      K /= 2;
    }
    cout << answer;
  }
}