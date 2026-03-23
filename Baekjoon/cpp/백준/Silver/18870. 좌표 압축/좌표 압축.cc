#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  map<int, int> m;
  vector<int> v(N);

  for (auto &i : v) {
    cin >> i;
    m[i] = 1;
  }

  int idx = 0;
  for(auto &[key, val] : m) val = idx++;
  for(auto i : v) cout << m[i] << " ";
}