#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int gcd(int a, int b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  int maxVal = 0, s;
  ll answer = N;
  vector<int> arr;
  vector<ll> cnt(2000001, 0);
  REP(i, 0, N-1) {
    cin >> s;
    maxVal = max(s, maxVal);
    for(int x=1 ; x*x <= s ; x++) {
      if(s % x == 0) {
        cnt[x]++;
        if(s / x != x) cnt[s/x]++;
      }
    }
  }

  REP(i, 2, maxVal) {
    if(cnt[i] < 2) continue;
    answer = max(answer, cnt[i] * i);
  }
  cout << answer;
}