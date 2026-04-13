#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int N; cin >> N;
  int answer = 0, need = 0;
  while (N--) {
    int a; cin >> a;
    if (a == need) {
      ++answer;
      ++need;
      need %= 3;
    }
  }

  cout << answer;
}