#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MAX_N = 100'001;
int N, M;
vector<ll> A(MAX_N);
vector<ll> tree(4*MAX_N);

ll query(int node, int nodeLeft, int nodeRight, int idx) {
  if (idx < nodeLeft || nodeRight < idx) return 0;
  if (nodeLeft == nodeRight) return tree[node];

  int nodeMid = (nodeLeft + nodeRight) / 2;
  return tree[node] + query(node*2, nodeLeft, nodeMid, idx) + query(node*2+1, nodeMid+1, nodeRight, idx);
}

void update(int node, int nodeLeft, int nodeRight, int left, int right, ll k) {
  if (left <= nodeLeft && nodeRight <= right) {
    tree[node] += k;
    return;
  }
  
  if (right < nodeLeft || nodeRight < left || nodeLeft == nodeRight) return;

  int nodeMid = (nodeLeft + nodeRight) / 2;
  update(node*2, nodeLeft, nodeMid, left, right, k);
  update(node*2+1, nodeMid+1, nodeRight, left, right, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;
  for (int i=1 ; i<=N ; i++) cin >> A[i];
  cin >> M;
  
  while (M--) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      ll i, j, k; cin >> i >> j >> k;
      update(1, 1, N, i, j, k);
    } else { // cmd == 2
      int x; cin >> x;
      cout << A[x] + query(1, 1, N, x) << "\n";
    }
  }
}