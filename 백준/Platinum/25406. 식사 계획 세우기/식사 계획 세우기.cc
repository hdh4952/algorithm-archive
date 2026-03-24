#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MAX_N = 300'010;
int N;
vector<int> arr(MAX_N, 0);
vector<int> cnt(MAX_N, 0);
vector<bool> vis(MAX_N, false);
vector<queue<int>> q_list(MAX_N, queue<int>());

struct Cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) return a.first < b.first;
    return q_list[b.second].front() > q_list[b.second].front();
  }
};

// {식당메뉴 파는 식당 개수, 식당 메뉴}
// 식당 개수가 클수록, 식당 메뉴를 파는 식당 중 가장 작은 식당 번호가 작을수록 먼저옴
priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;

int calc(int n) {
  if (n & 1) return n / 2 + 1;
  return n;
}

void solve() {
  vector<int> answer;

  int visIndex = 1, temp = 1;
  int pre = 0;
  for (int i=1 ; i<=N ; i++) {
    while (q_list[pq.top().second].empty() || vis[q_list[pq.top().second].front()]) {
      auto [count, menu] = pq.top();
      pq.pop();
      while (!q_list[menu].empty() && vis[q_list[menu].front()]) {
        q_list[menu].pop();
      }
      if (!q_list[menu].empty()) {
        pq.push({q_list[menu].size(), menu});
      }
    }

    if (pq.top().first >= calc(N-i+1)) {
      auto [count, menu] = pq.top();
      pq.pop();

      int store = q_list[menu].front();
      q_list[menu].pop();
      vis[store] = true;
      answer.push_back(store);
      pre = menu;
      if (count > 1) pq.push({count-1, menu});
    } else {
      visIndex = temp;
      while (vis[visIndex]) {
        ++visIndex;
        temp = visIndex;
      }
      while (vis[visIndex] || arr[visIndex] == pre) {
        ++visIndex;
      }
      vis[visIndex] = true;
      answer.push_back(visIndex);
      pre = arr[visIndex];
      ++visIndex;
    }
  }

  for (auto i : answer) cout << i << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;
  for (int i=1 ; i<=N ; i++) {
    cin >> arr[i];
    ++cnt[arr[i]];
    q_list[arr[i]].push(i);
  }

  for (int i=1 ; i<=N ; i++) {
    if (cnt[i] > 0) {
      pq.push({cnt[i], i});
    }
  }

  if (pq.top().first >= N / 2 + 1 + (N & 1)) cout << "-1";
  else solve();
}
