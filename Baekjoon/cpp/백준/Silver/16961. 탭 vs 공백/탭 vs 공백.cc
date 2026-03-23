#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> data(367, {0, 0});
    vector<int> answer(5, 0);
    int N; cin >> N;
    char ch;
    int s, e;
    REP(i, 1, N) {
        cin >> ch >> s >> e;
        answer[4] = max(answer[4], e - s + 1);
        if(ch == 'T') {
            REP(d, s, e) {
                data[d].first++;
            }
        } else {
            REP(d, s, e) {
                data[d].second++;
            }
        }
    }

    for(auto [a, b] : data) {
        if(a + b) answer[0]++;
        if(a && b && a == b) {
            answer[2]++;
            answer[3] = max(answer[3], a + b);
        }
        answer[1] = max(answer[1], a + b);
    }

    for(auto ans : answer) cout << ans << "\n";
}