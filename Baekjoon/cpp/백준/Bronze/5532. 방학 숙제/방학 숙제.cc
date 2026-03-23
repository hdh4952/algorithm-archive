#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int L, A, B, C, D; cin >> L >> A >> B >> C >> D;
  A = A / C + (A % C ? 1 : 0);
  B = B / D + (B % D ? 1 : 0);
  L -= max(A, B);
  cout << L;
}