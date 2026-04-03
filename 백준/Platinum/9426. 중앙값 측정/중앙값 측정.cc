#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 250'000;
const int MAX_TEMP = 65535;
int N, K;
vector<int> arr(MAX_N);
vector<int> tree(4*MAX_TEMP);

int update(int node, int nodeLeft, int nodeRight, int idx, int val) {
  if (idx < nodeLeft || nodeRight < idx) return tree[node];
  if (nodeLeft == nodeRight) {
    return tree[node] += val;
  }

  int mid = (nodeLeft + nodeRight) / 2;
  return tree[node] = update(node*2, nodeLeft, mid, idx, val) + update(node*2+1, mid+1, nodeRight, idx, val);
}

int query(int node, int nodeLeft, int nodeRight, int k) {
  if (nodeLeft == nodeRight) {
    return nodeLeft;
  }

  int mid = (nodeLeft + nodeRight) / 2;
  if (tree[node*2] >=  k) return query(node*2, nodeLeft, mid, k);
  return query(node*2+1, mid+1, nodeRight, k-tree[node*2]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  ll ans = 0;
  for (int i=0 ; i<N ; i++) {
    cin >> arr[i];
  }

  for (int i=0 ; i<K ; i++) {
    update(1, 0, MAX_TEMP, arr[i], 1);
  }

  for (int i=K ; i<N ; i++) {
    ans += query(1, 0, MAX_TEMP, (K+1)/2);
    update(1, 0, MAX_TEMP, arr[i], 1);
    update(1, 0, MAX_TEMP, arr[i-K], -1);
  }
  
  ans += query(1, 0, MAX_TEMP, (K+1)/2);
  cout << ans;
}