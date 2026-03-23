#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

vector<int> v[100001];
vector<char> Ci(100001);
vector<int> uf(100001, 0), cnt(100001, 1);

int find(int a) {
  return uf[a] = a == uf[a] ? a : find(uf[a]);
}

void merge(int a, int b) {
  int x = find(a), y = find(b);
  cnt[x] += cnt[y];
  cnt[y] = 0;
  uf[y] = x;
}

int findRed(int start) {
  int answer = 0;
  for(auto nxt : v[start]) {
    if(Ci[nxt] == 'R') {
      answer += cnt[find(nxt)];
    }
  }

  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N; cin >> N;
  int a, b;
  ll answer = 0;

  REP(i, 1, N - 1) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  REP(i, 1, N) {
    cin >> Ci[i];
    uf[i] = i;
  }

  REP(i, 1, N) {
    if(Ci[i] == 'R') {
      for(auto nxt : v[i]) {
        if(Ci[nxt] == 'R' && find(i) != find(nxt))
          merge(i, nxt);
      }
    }
  }

  REP(i, 1, N) {
    if(Ci[i] == 'B')
      answer += findRed(i);
  }

  cout << answer;
}