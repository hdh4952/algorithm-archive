#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int A, B, C;
  cin >> A >> B >> C;
  int N;
  cin >> N;
  int a, b, c, sum;
  vector<int> score;
  REP(i, 1, N) {
    sum = 0;
    REP(j, 1, 3) {
      cin >> a >> b >> c;
      sum += A * a + B * b + C * c;
    }
    score.push_back(sum);
  }

  sort(score.begin(), score.end(), greater<>());
  cout << score.front();
}