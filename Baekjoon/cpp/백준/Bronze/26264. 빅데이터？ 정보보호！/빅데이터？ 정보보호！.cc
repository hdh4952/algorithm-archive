#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  int a = 0, b = 0;
  string s;
  cin >> s;
  REP(i, 0, s.size()-1) {
    if(s[i] == 's') {
      a++;
      i += 7;
    } else {
      b++;
      i += 6;
    }
  }

  if(a == b) cout << "bigdata? security!";
  else if(a > b) cout << "security!";
  else cout << "bigdata?";
}