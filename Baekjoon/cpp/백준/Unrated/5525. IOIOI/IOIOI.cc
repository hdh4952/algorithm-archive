#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  string s;
  cin >> N >> M >> s;

  string pn = "I";
  for(int i=0; i<N ; i++) pn += "OI";

  int answer = 0 ;
  for(int i=0 ; i<=M-(2*N+1); i++) {
    if(s.substr(i, 2*N+1) == pn) answer++;
  }
  cout << answer;
}