#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int gcd(int x, int y) {
  if(x < y) swap(x, y);
  if(y == 0) return x;
  else return gcd(y, x % y);
}

bool isGone(int x, int y, vector<int> dist) {
  int cmp = dist.back();
  dist.pop_back();
  for(auto d : dist) cmp = gcd(cmp, d);
  if(x % cmp == 0 && y % cmp == 0) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  int X, Y, K;

  REP(i, 1, N) {
    cin >> X >> Y >> K;
    vector<int> dist(K, 0);
    REP(j, 0, K-1) cin >> dist[j];
    if(isGone(X, Y, dist)) cout << "Ta-da\n";
    else cout << "Gave up\n";
  }
}