#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300'010;
int N;
int arr[MAX_N];
int cnt[MAX_N];
queue<int> q[MAX_N];
priority_queue<pair<int, int>> pq;
set<pair<int, int>> first_idx;

void solve() {
  for (int i=1 ; i<=N ; i++) {
    if (cnt[i] > 0) {
      if (cnt[i] > (N+1) / 2) {
        cout << "-1";
        return;
      }
      pq.push({cnt[i], i});
      first_idx.insert({q[i].front(), i});
    }
  }

  int prev = -1;
  vector<int> answer(N);
  for (int i=1 ; i<=N ; i++) {
    while (!pq.empty() && cnt[pq.top().second] != pq.top().first) {
      pq.pop();
    }

    int remain = N - i + 1;
    if (pq.top().first * 2 > remain) {
      auto [count, menu] = pq.top();
      --cnt[menu];
      answer[i-1] = q[menu].front();
      q[menu].pop();
      first_idx.erase({answer[i-1], menu});
      if (count > 1) {
        pq.push({count - 1, menu});
        first_idx.insert({q[menu].front(), menu});
      }
      prev = menu;
    } else {
      auto it = first_idx.begin();
      if (it->second == prev) {
        it = next(it);
      }
      int idx = it->first;
      int menu = arr[idx];
      --cnt[menu];
      answer[i-1] = q[menu].front();
      q[menu].pop();
      first_idx.erase({answer[i-1], menu});
      if (cnt[menu]) {
        first_idx.insert({q[menu].front(), menu});
        pq.push({cnt[menu], menu});
      }
      prev = menu;
    }
  }

  for (auto i : answer) cout << i << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;
  for (int i=1 ; i<=N ; i++) {
    cin >> arr[i];
    ++cnt[arr[i]];
    q[arr[i]].push(i);
  }

  solve();
}