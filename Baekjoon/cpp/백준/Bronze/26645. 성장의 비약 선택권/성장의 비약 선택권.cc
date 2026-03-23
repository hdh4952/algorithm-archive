#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  if(200 <= N && N < 206) {
    cout << "1";
  } else if(N < 218) {
    cout << "2";
  } else if(N < 229) {
    cout << "3";
  } else cout << "4";
}