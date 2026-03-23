#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
typedef long long int ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> v{1, 0, 0};
  string s;
  cin >> s;
  for(auto ch : s) {
    if(ch == 'A') swap(v[0], v[1]);
    if(ch == 'B') swap(v[1], v[2]);
    if(ch == 'C') swap(v[0], v[2]);
  }
  cout << find(v.begin(), v.end(), 1) - v.begin() + 1;
}