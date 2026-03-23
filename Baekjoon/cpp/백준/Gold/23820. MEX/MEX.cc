#include <bits/stdc++.h>
#define MAXA 2'000'003
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<bool> num(MAXA + 1, false);
  vector<bool> answer(MAXA + 1, false);

  for(int i=0 ; i<n ; i++) {
    int a;
    cin >> a;
    num[a] = true;
  }

  if(!num[0]) {
    cout << "0";
    return 0;
  }

  for(int i=1 ; i<MAXA+1 ; i++) {
    if(!num[i]) continue;
    for(int j=1 ; j<=MAXA/i ; j++) {
      if(!num[j]) continue;
      answer[i * j] = true;
    }
  }

  for(int i=1 ; i<MAXA+1 ; i++) {
    if(!answer[i]) {
      cout << i;
      return 0;
    }
  }
}