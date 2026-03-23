#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

bool win(int a, int b) {
  if (a < b) swap(a, b); // always a >= b
  if (a % b == 0) return true;
  if (a / b >= 2) return true;
  if (!win(a % b, b)) return true;
  return false;
}

void solve(int a, int b) {
  if (win(a, b)) cout << "A wins\n";
  else cout << "B wins\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b;
  while (true) {
    cin >> a >> b;
    if (!(a || b)) break;
    solve(a, b);
  }
}