#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

map<string, int> m;
vector<string> items;

int nodeNum(const string& s) {
    if(m.find(s) != m.end()) return m[s];
    m[s] = int(items.size());
    items.push_back(s);
    return m[s];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int a, b;
    string A, B;
    vector<int> v[400000];
    vector<int> deg(400000, 0);

    REP(i, 1, N) {
        cin >> A >> B;
        a = nodeNum(A);
        b = nodeNum(B);
        v[a].push_back(b);
        deg[b]++;
    }

    queue<int> q;
    vector<int> ans;

    REP(i, 0, items.size()-1) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int qsize = int(q.size());
        vector<int> temp;
        REP(i, 1, qsize) {
            int now = q.front();
            q.pop();
            temp.push_back(now);
            for(auto nxt : v[now]) {
                deg[nxt]--;
                if(!deg[nxt]) q.push(nxt);
            }
        }
        sort(temp.begin(), temp.end(), [](int x, int y){return items[x] < items[y];});
        ans.insert(ans.end(), temp.begin(), temp.end());
    }

    if(ans.size() != items.size()) cout << "-1";
    else for(auto i : ans) cout << items[i] << "\n";
}