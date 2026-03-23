#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    vector<int> ans;

    for (auto &[a, b]: v) cin >> a >> b;
    sort(v.begin(), v.end(), cmp);
    for (auto [a, b]: v) {
        int tmp = 0;
        for (auto [cost, delivery]: v) {
            if (a > cost) continue;
            if (a - delivery < 0) continue;
            tmp += a - delivery;
        }
        ans.push_back(tmp);
    }

    int cmpValue = 0, answer = -1;
    REP(i, 0, N - 1) {
        if (cmpValue < ans[i]) {
            cmpValue = ans[i];
            answer = i;
        }
    }

    if (answer == -1) cout << "0";
    else cout << v[answer].first;
}