#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int L;
  cin >> L;
  ll ai, r = 1, M = 1234567891, H = 0;
  char ch;

  REP(i, 1, L) {
    cin >> ch;
    ai = ch - 'a' + 1;
    H += (ai * r) % M;
    r *= 31;
  }

  cout << H;
}