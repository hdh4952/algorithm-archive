#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N;
  for (int i=0 ; i<N/2 ; i++) {
    double a, b; cin >> a >> b;

    int hi = (a * 2) / 45;
    int lo = (b * 2) / 45;
    
    cout << (char)(hi * 16 + lo);
  }

}