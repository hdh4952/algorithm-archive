#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> cnt(8001, 0);
  vector<int> v(N);
  for (auto &i : v) {
    cin >> i;
    cnt[i + 4000]++;
  }

  int sum = accumulate(v.begin(), v.end(), 0);
  sum = round(double(sum) / double(N));
  cout << sum << "\n";

  sort(v.begin(), v.end());
  cout << v[N / 2] << "\n";

  int cmp = 0, answer;
  bool isFirst = false;
  REP(i, 0, 8001) {
    if (cnt[i] > cmp) {
      cmp = cnt[i];
      answer = i;
      isFirst = true;
    } else if (cnt[i] == cmp && isFirst) {
      cmp = cnt[i];
      answer = i;
      isFirst = false;
    }
  }
  cout << answer - 4000 << "\n";

  cout << v.back() - v.front();
}