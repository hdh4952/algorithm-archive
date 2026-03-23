#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int songCnt;
vector<int> pKnowSong[101];

void shareSongs(vector<int> campfire) {
  vector<int> song(songCnt + 1, 0);
  for (auto p : campfire) {
    for (auto s : pKnowSong[p]) {
      song[s] = 1;
    }
  }

  for (auto p : campfire) {
    REP(i, 1, songCnt) {
      if (find(pKnowSong[p].begin(), pKnowSong[p].end(), i) == pKnowSong[p].end()) pKnowSong[p].push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, E, K;
  cin >> N >> E;
  REP(i, 1, E) {
    cin >> K;
    vector<int> campfire(K, 0);
    REP(j, 1, K) cin >> campfire[j - 1];
    if (find(campfire.begin(), campfire.end(), 1) != campfire.end()) {
      songCnt++;
      for (auto p : campfire) pKnowSong[p].push_back(songCnt);
    } else shareSongs(campfire);
  }

  REP(i, 1, N) if (songCnt == pKnowSong[i].size()) cout << i << "\n";
}