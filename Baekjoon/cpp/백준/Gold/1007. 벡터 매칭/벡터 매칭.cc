#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpll;

double answer;

pair<ll, ll> getVec(pair<ll, ll> a, pair<ll, ll> b) {
  return {a.first - b.first, a.second - b.second};
}

pair<ll, ll> addVec(pair<ll, ll> a, pair<ll, ll> b) {
  return {a.first + b.first, a.second + b.second};
}

double getDistance(pair<ll, ll> &a) {
  return sqrt(a.first * a.first + a.second * a.second);
}

void makeCase(vpll &v, int N, int now, vi &temp) {
  if (N == temp.size()) {
    vi a = temp, b;
    for (int i = 0; i < 2 * N; i++)
      if (end(temp) == std::find(temp.begin(), temp.end(), i))
        b.push_back(i);

    pair<ll, ll> cmp{0, 0};
    for (int i = 0; i < N; i++) {
      cmp = addVec(cmp, getVec(v[a[i]], v[b[i]]));
    }
    answer = min(answer, getDistance(cmp));
    return;
  }
  if (N + temp.size() < now)
    return;

  for (int i = now; i < v.size(); i++) {
    temp.push_back(i);
    makeCase(v, N, i + 1, temp);
    temp.pop_back();
  }
}

void solve() {
  int N;
  cin >> N;

  answer = DBL_MAX;
  vpll v(N);
  vi temp;
  for (auto &[x, y] : v)
    cin >> x >> y;

  makeCase(v, N / 2, 0, temp);
  cout << fixed << setprecision(12);
  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}