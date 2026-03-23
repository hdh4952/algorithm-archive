#include <bits/stdc++.h>
using namespace std;

void makeChannel(int cnt, int now, vector<int> &broken, vector<int> &channelList) {
  if (cnt == 7) return;
  channelList.push_back(now);
  for (int i = 0; i < 10; i++) {
    if (broken[i] || !cnt && !i) continue;
    makeChannel(cnt + 1, now * 10 + i, broken, channelList);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, brokenBtn;
  cin >> N >> M;
  vector<int> channelList, broken(10);
  while (M--) {
    cin >> brokenBtn;
    broken[brokenBtn] = 1;
  }

  for(int i=0 ; i<10 ; i++) {
    if(!broken[i]) makeChannel(1, i, broken, channelList);
  }

  int answer = 1e9;
  for (auto i : channelList) {
    answer = min(answer, abs(N - i) + int(to_string(i).size()));
  }
  answer = min(answer, abs(N - 100));
  cout << answer;
}