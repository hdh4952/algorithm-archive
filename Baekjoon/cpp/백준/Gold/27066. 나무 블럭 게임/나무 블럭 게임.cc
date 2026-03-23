#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

bool cmp(pair<int,int> a, pair<int, int> b) {
    double x = (double) a.first / (double) a.second;
    double y = (double) b.first / (double) b.second;
    return x > y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> v;
    int Ai;
    REP(i, 1, N) {
        cin >> Ai;
        v.emplace_back(Ai, 1);
    }

    double answer = 0.0;
    sort(v.begin(), v.end(), cmp);
    REP(i, 1, N) {
        answer = max(answer, (double)v[v.size() / 2].first / (double)v[v.size() / 2].second);
        pair<int, int> temp = v.back();
        v.pop_back();
        if(v.empty()) continue;
        v.back().first += temp.first;
        v.back().second += temp.second;
    }
    cout.precision(10);
    cout << answer;
}