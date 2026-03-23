#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int idx = 1;
vector<int> tree[100000];
map<int, string> getName;

vector<string> split(const string &str);
int isExist(int index, const string &name);
void dfs(int parent, int depth);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  string str;

  cin >> N;
  REP(i, 1, N) {
    int parent = 0, child;
    cin >> str;

    for (const auto &dir : split(str)) {
      child = isExist(parent, dir);
      if (!child) {
        child = idx++;
        getName[child] = dir;
        tree[parent].push_back(child);
      }
      parent = child;
    }
  }

  dfs(0, 0);
}

vector<string> split(const string &str) {
  vector<string> answer;
  string s;

  for (auto c : str) {
    if (c == '\\') {
      answer.push_back(s);
      s = "";
    } else s += c;
  }
  answer.push_back(s);

  return answer;
}

int isExist(int index, const string &dirName) {
  for (auto now : tree[index])
    if (getName[now] == dirName) return now;
  return false;
}

void dfs(int parent, int depth) {
  sort(tree[parent].begin(), tree[parent].end(), [](int a, int b) { return getName[a] < getName[b]; });
  for (auto nxt : tree[parent]) {
    REP(i, 1, depth) cout << " ";
    cout << getName[nxt] << "\n";
    dfs(nxt, depth + 1);
  }
}