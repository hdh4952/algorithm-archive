#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> v(9);
    vector<int> ans(9, 0);
    for (auto &[x, y]: v) {
        cin >> x >> y;
    }

    REP(i, 1, 9) {
        int cnt = 0;
        for (auto [x, y]: v) {
            if (x == 1 && y == i) cnt++;
            if (x == 0 && y != i) cnt++;
        }
        if (cnt == 8) ans[i - 1] = i;
    }

    int answer = 0;
    for(auto i : ans) {
        if(i && !answer) answer = i;
        else if(i) answer = -1;
    }
    if(!answer || answer == -1) cout << "-1";
    else cout << answer;
}