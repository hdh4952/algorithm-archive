#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, L;
  cin >> N >> M >> L;
  int bookLen = 0, temp;
  while (N--) {
    cin >> temp;
    bookLen += temp;
  }

  if (bookLen == M) cout << "0";
  else if ((L <= bookLen && bookLen < M) || (bookLen < M && M >= bookLen + L)) cout << "1";
  else cout << "-1";
}