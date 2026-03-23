#include <bits/stdc++.h>

#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

void solve(int n) {
    vector<pair<string, vector<int>>> v;
    vector<pair<string, string>> answer;
    REP(i, 0, n - 1) {
        string name;
        cin >> name;
        vector<int> nasty;
        REP(j, 1, n - 1) {
            char msg;
            cin >> msg;
            if (msg == 'N') nasty.push_back((i + n - j) % n);
        }
        v.emplace_back(name, nasty);
    }

    for (auto [name, nasty]: v) {
        if (nasty.empty()) continue;
        for (auto i: nasty) answer.emplace_back(v[i].first, name);
    }

    if (answer.empty()) cout << "Nobody was nasty\n";
    else for (auto [a, b]: answer) cout << a << " was nasty about " << b << "\n";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, idx = 1;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Group " << idx++ << "\n";
        solve(N);
    }
}