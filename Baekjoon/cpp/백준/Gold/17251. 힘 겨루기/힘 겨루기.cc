#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> v(N);
  for(auto &i : v)
    cin >> i;

  vector<int> leftScore(N), rightScore(N);
  leftScore[0] = v[0];
  rightScore[N-1] = v[N-1];
  for(int i=1 ; i<N ; i++) {
    leftScore[i] = max(leftScore[i-1], v[i]);
    rightScore[N-i-1] = max(rightScore[N-i], v[N-i-1]);
  }

  vector<int> cnt(3, 0);
  for(int i=0 ; i<N-1 ; i++) {
    if(leftScore[i] > rightScore[i+1]) cnt[0]++;
    else if(leftScore[i] == rightScore[i+1]) cnt[1]++;
    else cnt[2]++;
  }
  
  if(cnt.front() == cnt.back()) cout << "X";
  else if(cnt.front() > cnt.back()) cout << "R";
  else cout << "B";
}