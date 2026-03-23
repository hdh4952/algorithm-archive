#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/22862
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> v(N);
  for(auto &i : v) {
    cin >> i;
    i = !(i & 1);
  }

  int s=0, e=0, answer = 0, temp=0;
  while(s < v.size()) {
    if(v[s] == 1) {
      temp++;
      answer = max(answer, temp);
      s++;
    } else {
      if(K) {
        K--;
        s++;
      } else {
        while(e <= s) {
          if(v[e]) {
            temp--;
            e++;
          } else {
            K++;
            e++;
            break;
          }
        }
      }
    }
  }

  cout << answer;
}