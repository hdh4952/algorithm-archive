#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &v) {
  if(v.size() == 1) return 0;
  if(v.size() == 2) return v[0] * v[1];
  vector<int> a, b;
  int aSize = 0, bSize = 0;
  for(auto i : v) {
    if(aSize <= bSize) {
      a.push_back(i);
      aSize += i;
    } else {
      b.push_back(i);
      bSize += i;
    }
  }
  return aSize * bSize + f(a) + f(b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  sort(v.begin(), v.end(), greater<>());
  cout << f(v);
}