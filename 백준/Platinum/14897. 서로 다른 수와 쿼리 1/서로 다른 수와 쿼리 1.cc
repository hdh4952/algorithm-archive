#include <bits/stdc++.h>
using namespace std;

int N, Q;
const int MAX_VALUE = 1'000'010;
vector<int> arr(MAX_VALUE), pre(MAX_VALUE);
vector<tuple<int, int, int>> queries;
vector<int> cnt(MAX_VALUE, 0);
map<int, int> m;
int sum = 0;

void add(int idx) {
  if (cnt[arr[idx]]++ == 0) sum++;
}

void remove(int idx) {
  if (--cnt[arr[idx]] == 0) sum--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;
  for (int i=0 ; i<N ; i++) {
    int x; cin >> x;
    arr[i] = pre[i] = x;
  }

  cin >> Q;
  for (int i=0 ; i<Q ; i++) {
    int a, b; cin >> a >> b;
    queries.push_back({i, a-1, b-1});
  }

  int answerIdx = 0;
  sort(pre.begin(), pre.begin() + N);
  for (int i=0 ; i<N ; i++) {
    if (m.find(pre[i]) == m.end()) {
      m[pre[i]] = answerIdx++;
    }
  }
  for (int i=0 ; i<N ; i++) {
    arr[i] = m[arr[i]];
  }

  int blockSize = sqrt(N);
  sort(queries.begin(), queries.end(), [blockSize](auto q1, auto q2) {
      auto [idx1, L1, R1] = q1;
      auto [idx2, L2, R2] = q2;
      int b1 = L1 / blockSize;
      int b2 = L2 / blockSize;
      if (b1 != b2) return b1 < b2;
      if (b1 & 1) return R1 > R2;
      return R1 < R2;
  });

  vector<int> answer(Q);
  int left = 0, right = -1;
  for (auto [idx, L, R] : queries) {
    while (L < left) add(--left);
    while (right < R) add(++right);
    while (L > left) remove(left++);
    while (right > R) remove(right--);
    answer[idx] = sum;
  }

  for (auto i : answer) cout << i << "\n";
}

