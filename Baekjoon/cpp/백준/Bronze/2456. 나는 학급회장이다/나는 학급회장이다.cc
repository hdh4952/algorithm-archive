#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<vector<int>> vote(3, vector<int>(4, 0));

bool cmp(int a, int b) {
  if (vote[a][0] != vote[b][0]) return vote[a][0] > vote[b][0];
  if (vote[a][3], vote[b][3]) return vote[a][3] > vote[b][3];
  if (vote[a][2], vote[b][2]) return vote[a][2] > vote[b][2];
  return a < b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, a, b, c, answer = 0;
  cin >> n;
  REP(i, 1, n) {
    cin >> a >> b >> c;
    vote[0][a]++;
    vote[1][b]++;
    vote[2][c]++;
    vote[0][0] += a;
    vote[1][0] += b;
    vote[2][0] += c;
  }

  vector<int> result = {0, 1, 2};
  sort(result.begin(), result.end(), cmp);
  a = result[0];
  b = result[1];
  if (vote[a][0] == vote[b][0] && vote[a][3] == vote[b][3] && vote[a][2] == vote[b][2]) cout << "0 " << vote[a][0];
  else cout << a + 1 << " " << vote[a][0];
}