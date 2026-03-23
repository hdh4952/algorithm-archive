#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  string name;
  int age, w;

  while(cin >> name >> age >> w) {
    if(name == "#" && !age && !w) break;
    cout << name << " ";
    if(age > 17 || w >= 80) cout << "Senior\n";
    else cout << "Junior\n";
  }
}