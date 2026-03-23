#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> v(N + 1, 0);
    vector<pair<int, int>> data(M);

    for (auto &[a, b]: data) cin >> a >> b;
    ll answer = 0;
    sort(data.begin(), data.end());
    for (auto [a, b]: data) {
        answer += v[b];
        REP(i, 1, b-1) v[i]++;
    }
    cout << answer;
}