#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll sum = 1, a = 0, N;
  cin >> N;
  REP(i, 1, 1000000) {
    sum += a;
    a += 6;
    if(sum >= N) {
      cout << i;
      break;
    }
  }
}