#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string A, B, answer;
  char c;
  cin >> A >> c >> B;
  if(c == '+') {
    if(A.size() == B.size()) {
      cout << "2";
      REP(i, 1, A.size() - 1) cout << "0";
    } else {
      if(A.size() < B.size()) swap(A, B);
      REP(i, A.size() - B.size(), A.size() - 1) {
        A[i] = B[i - A.size() + B.size()];
      }
      cout << A;
    }
  } else {
    cout << "1";
    REP(i, 1, A.size() + B.size() - 2) cout << "0";
  }
}