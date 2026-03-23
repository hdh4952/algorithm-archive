#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    map<int, vector<int>> m;
    int a, b, answer = 0;
    REP(i, 1, N) {
        cin >> a >> b;
        if(m.find(a) == m.end()) {
            vector<int> v;
            m[a] = v;
        }
        m[a].push_back(b);
    }

    for(auto [p, v] : m) {
        queue<int> q;
        for(auto i : v) q.push(i);
        bool state = false;
        while(!q.empty()) {
            if(q.size() == 1 && q.front() == 1) answer++;
            if(!state && q.front() == 0 || state && q.front() == 1) answer++;
            else state = !state;
            q.pop();
        }
    }

    cout << answer;
}