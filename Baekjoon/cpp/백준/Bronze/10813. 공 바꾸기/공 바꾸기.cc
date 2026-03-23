#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> v(N+1, 0);
  iota(v.begin(), v.end(), 0);
  while(M--) {
    int i, j;
    cin >> i >> j;
    swap(v[i], v[j]);
  }

  for(int i=1 ; i<=N ; i++)
    cout << v[i] << " ";

}