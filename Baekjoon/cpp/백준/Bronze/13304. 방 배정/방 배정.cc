#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K, S, grade, answer = 0;
  vector<int> v(5, 0);

  cin >> N >> K;

  REP(i, 1, N) {
    cin >> S >> grade;
    if(grade == 1 || grade == 2) v[0]++;
    if(grade == 3 || grade == 4) {
      if(S == 0) v[1]++;
      if(S == 1) v[2]++;
    }
    if(grade == 5 || grade == 6) {
      if(S == 0) v[3]++;
      if(S == 1) v[4]++;
    }
  }

  for(auto i : v) answer += i / K + (i % K ? 1 : 0);
  cout << answer;
}