#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

vector<pair<int, int>> tree[10001]; // {child_node, cost}
vector<bool> is_check_distance(10001, false);
vector<int> node_distance(10001, 0);

/**
 * @brief : check distance
 * @return : the distance to the farthest node
 * @param : node number to know the distance
 */
int check_node_distance(int N) {
  if (is_check_distance[N]) return node_distance[N];
  is_check_distance[N] = true;
  int maxLen = 0;
  for (auto [child_node, cost] : tree[N]) maxLen = max(maxLen, check_node_distance(child_node) + cost);
  return node_distance[N] = maxLen;
}

/**
 * @brief : solve problem
 * @return : minimum cost
 * @param root : root node number
 * @param H : height of tree
 */
int solve(int root, int H) {
  int answer = 0;
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (auto [child_node, cost] : tree[now]) {
      if (cost + check_node_distance(child_node) <= H) continue;
      if (check_node_distance(child_node) > H) {
        answer += cost;
        q.push(child_node);
      } else
        answer += check_node_distance(child_node) + cost - H;
    }
  }

  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, H, root, parent, cost;
  cin >> N >> H;

  REP(i, 1, N) {
    cin >> parent >> cost;
    if(parent == 0) root = i;
    tree[parent].push_back({i, cost});
  }

  cout << solve(root, H);
}