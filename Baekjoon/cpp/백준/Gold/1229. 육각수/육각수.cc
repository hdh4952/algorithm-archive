#include <bits/stdc++.h>
using namespace std;

int answer = 6;
vector<int> memo(1'000'000, 6);

void findN(vector<int> &temp, int maxCnt, int n, int nowIdx, vector<int> &sixNumber) {
  if(n == 0) {
    answer = min(answer, int(temp.size()));
    return;
  }
  if(temp.size() >= answer) return;
  for(int i=nowIdx ; i<sixNumber.size() ; i++) {
    if(sixNumber[i] > n) continue;
    if(temp.size() == maxCnt - 1 && sixNumber[i] != n) continue;
    temp.push_back(sixNumber[i]);
    findN(temp, maxCnt, n - sixNumber[i], i, sixNumber);
    temp.pop_back();
  }
}

void solve(int n, vector<int> &sixNumber) {
  if(n == 11 || n == 26) return;
  vector<int> temp;
  if(n <= 130)
    findN(temp, answer=5, n, 0, sixNumber);
  else if(n <= 146'858)
    findN(temp, answer=4, n, 0, sixNumber);
  else
    findN(temp, answer=3, n, 0, sixNumber);
}

void init(vector<int> &v) {
  v.push_back(1);
  int sixNumber = 1;
  for(int i=1 ; sixNumber<1'000'000 ; i++) {
    sixNumber = v[i - 1] + 4 * (i + 1) - 3;
    v.push_back(sixNumber);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> sixNumber;
  init(sixNumber);
  std::reverse(sixNumber.begin(), sixNumber.end());
  solve(n, sixNumber);
  cout << answer;
}