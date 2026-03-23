#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &uf, int a) {
    return uf[a] = a == uf[a] ? a : find(uf, uf[a]);
}

void merge(vector<int> &uf, int a, int b) {
    auto x = find(uf, a), y = find(uf, b);
    uf[y] = x;
}

void update(vector<vector<int>> &adj) {
    for(int k=0 ; k<adj.size() ; k++) {
        for(int i=0 ; i<adj.size() ; i++) {
            for(int j=0 ; j<adj.size() ; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> cost(N, vector<int>(N)), adj(N, vector<int>(N, 3000));
    vector<int> uf(N);
    iota(uf.begin(), uf.end(), 0);

    for(auto &i : cost)
        for(auto &j : i)
            cin >> j;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for(int i=0 ; i<N-1 ; i++)
        for(int j=i+1 ; j<N ; j++)
            pq.emplace(cost[i][j], i, j);

    int answer = 0;
    while(!pq.empty()) {
        auto [c, a, b] = pq.top();
        pq.pop();
        if(find(uf, a) != find(uf, b)) {
            adj[a][b] = c;
            adj[b][a] = c;
            merge(uf, a, b);
            answer += c;
        } else {
            update(adj);
            auto t = adj[a][b];
            if(t == c) continue;
            else if(t > c) {
                adj[a][b] = c;
                adj[b][a] = c;
                answer += c;
            } else {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << answer;
}