#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  string s; cin >> s;

  vector<int> fail(n, 0);
  for (int i=1, j=0 ; i<n ; i++) {
    while (j > 0 && s[i] != s[j]) {
      j = fail[j-1];
    }
    if (s[i] == s[j]) {
      fail[i] = ++j;
    }
  }

  cout << n - fail[n-1];
}
