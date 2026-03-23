#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

int input() {
  int h, m, s;
  cin >> h >> m >> s;
  return h * 3600 + m * 60 + s;
}

void solve() {
  int preTime = input(), nxtTime = input();
  int time = nxtTime - preTime;
  cout << time / 3600 << " " << time % 3600 / 60 << " " << time % 60 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 3;
  while(t--) solve();
}