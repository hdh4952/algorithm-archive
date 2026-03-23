#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int A, B, V;
  cin >> A >> B >> V;
  cout << (V - B) / (A - B) + ((V - B) % (A - B) != 0);
}