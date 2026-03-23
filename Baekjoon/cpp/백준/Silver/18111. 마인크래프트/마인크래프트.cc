#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, B;
  cin >> N >> M >> B;

  vector<vector<int>> v(N, vector<int>(M, 0));
  for (auto &i : v)
    for (auto &j : i)
      cin >> j;

  int answerTime = 1e9, answerHeight = -1;
  REP(height, 0, 256) {
    int t = 0, requiredBlock = -abs(B);
    for (const auto &i : v) {
      for (auto j : i) {
        if (j > height) {
          t += 2 * (j - height);
          requiredBlock -= j - height;
        } else if (j < height) {
          t += height - j;
          requiredBlock += height - j;
        }
      }
    }
    
    if (requiredBlock <= 0) {
      if (answerTime > t) {
        answerTime = t;
        answerHeight = height;
      } else if (answerTime == t && answerHeight < height) {
        answerTime = t;
        answerHeight = height;
      }
    }
  }

  cout << answerTime << " " << answerHeight;
}