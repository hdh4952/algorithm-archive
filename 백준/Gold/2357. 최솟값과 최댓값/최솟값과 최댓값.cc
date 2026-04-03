#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;
  vector<int> min_seg(N<<1, INF), max_seg(N<<1, 0);

  auto min_update = [&](int idx, int val) {
    min_seg[idx+=N] = val;
    while (idx >>= 1) {
      min_seg[idx] = min(min_seg[idx<<1], min_seg[idx<<1 | 1]);
    }
  };

  auto max_update = [&](int idx, int val) {
    max_seg[idx+=N] = val;
    while (idx >>= 1) {
      max_seg[idx] = max(max_seg[idx<<1], max_seg[idx<<1 | 1]);
    }
  };

  auto min_get = [&](int left, int right) {
    int ret = INF;
    for (left+=N, right+=N ; left<=right ; left>>=1, right>>=1) {
      if (left&1) ret = min(ret, min_seg[left++]);
      if (~right&1) ret = min(ret, min_seg[right--]);
    }
    
    return ret;
  };

  auto max_get = [&](int left, int right) {
    int ret = 0;
    for (left+=N, right+=N ; left<=right ; left>>=1, right>>=1) {
      if (left&1) ret = max(ret, max_seg[left++]);
      if (~right&1) ret = max(ret, max_seg[right--]);
    }
    return ret;
  };

  for (int i=0 ; i<N ; i++) {
    int x; cin >> x;
    min_update(i, x);
    max_update(i, x);
  }

  while (M--) {
    int a, b; cin >> a >> b;
    cout << min_get(a-1, b-1) << " " << max_get(a-1, b-1) << "\n";
  }
}